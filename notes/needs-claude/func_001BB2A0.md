# needs-claude: func_001BB2A0 (pilot P32)

- asm: `asm/SLES_539.74/game_1BB2A0.s`, size 0x4A0 (1184 B; last two words are
  align nops). Main binary, `-O3`.
- best C: `build/attempts/func_001BB2A0.c` — score 163 (160 `*` lines + 12/4
  size). Not committed.

## What it does

`s32 func_001BB2A0(void *p, s32 arg1)`.

- `d = *(s32 *)gp_rel(D_003E0664) + 0x6A20; if (!d) return 0;`
- tagged selector: `a2 = (p[0] == 1) ? (s32)(float)p[4] : p[4];` (bnel +
  cvt.w.s, P11/P07 idiom — reproduces byte-exactly as written).
- an 18-way compare chain `beql a2, v1, case` testing **descending**
  101, 100, 0x10, 0xE, 0xD, 0xC, 0xB, 0xA, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0;
  the value/pointer for each case is loaded in the beql's delay slot
  (`lw a0, off(d)`, cases 0-3 load into `v1`; `addiu a0, d, 0x1C` for 0x10).
  Default: `b 0x6A8; daddu v0, zero` → return 0.
- the target object `p` has four (selector, pointer-slot) pairs:
  `[8]→[0xC]+4`, `[0x10]→[0x14]+4`, `[0x18]→[0x1C]+4`, `[0x20]→[0x24]+4`;
  each store is guarded by `sel == 3` and stores either an int or a float
  from `d` (offsets used: ints 4,8,C,10,14,18,60,64,B0,C0,C4,CC,D0; floats
  30,34,38,40,44,48,50,54,58,90,98,A0,A4,A8).
- case 8 additionally calls `func_0012A038(d.f90, d.f98)` (f12/f13) and
  stores its float result through `[0x24]`; its f18-guard store targets
  `*(char **)(p + 0x18) + 4` = the `[0x1C]` slot (delay slot
  `addiu a1, s0, 0x18`).
- case 0x10: `r = func_0018F130(d + 0x1C, arg1); DebugPrintf(&D_003C4420, r);
  if (p[8]==3) *(s32 *)(p[0xC] + 4) = r;`
- case 0xB branches on `arg1`: 4 → three float stores (d.f40/44/48);
  2 → one store d.f44; otherwise nothing — `b 0x6A0; addiu v0, 1`
  (skips the shared `addiu v0, 1` at 0x69C by jumping to 0x6A0).
- all guard-fails and stores converge to `0x69C: addiu v0, zero, 1` →
  epilogue `0x724/0x728` (return 1); return-0 paths branch straight to
  0x6A8/0x6B0 → 0x724.

## What matched byte-exactly

Prologue, tagged conversion, the whole compare chain including the delay
slot value loads, and **all int-case bodies** (0-9, 13, 14, 64, 65):
`bne v0, a0(3), +return1; nop; lw v0, 0xC(s0); b return1; sw val, 4(v0)`
with the exact v0/v1/a0 register roles.

## Three shape fixes that mattered (worth an idiom entry)

1. **switch case order in the source decides the chain direction**: cases
   written ASCENDING (0,1,2,...,0x10,0x64,0x65) produce the descending
   beql chain; descending source produced ascending tests (score 286 → 250).
   Same for an if-chain (it also came out ascending).
2. **single trailing `return 1`** (cases end with `break;`): one shared
   return-1 merge block instead of a duplicated `addiu v0, 1` per case
   (score 250 → 191, size 1232 → 1184 at the time).
3. case 0x8 third store must go through `arg0 + 0x18` (the `[0x1C]` slot),
   not `[0x14]` (191 → 160).

## The wall (pure block placement — same family as P14/P15/P25/P31)

Remaining `*` lines (160) are all one of:
- branch target distances: the four float cases (8, 0xA, 0xB, 0xC) — the
  original places their three guarded-store blocks out-of-line at
  0x6B8-0x720 and keeps the guard sequence inline with
  `beq a0, v1, outofline; lwc1 f0, off(v0)` (float load in the delay
  slot, taken block does `lw v1, off(s0)/lw v1, 4(a1); b back; swc1 f0, 4(v1)`);
  my mwcc emits the stores as beql-taken inline blocks placed after the
  case bodies, at different addresses.
- case 0xB: original tests `beql a1, 4 / beql a1, 2` (constants 4 from the
  outer chain's delay slot at 0x32C) and returns via `b 0x6A0; addiu v0, 1`;
  mine inverts to `bne` + far branches and reuses the shared merge.
- case 0x10: mine schedules the `func_0018F130` call and `DebugPrintf`
  (lui/addiu string) in a different spot than the original's +0x390 block.
- mine is 12 B short (1172 vs 1184): missing the separate default block
  (`b 0x6A8` → `b 0x724; nop`) and the 0xB no-match `b 0x6A0; addiu v0, 1`.

## What was tried (18 try_match runs)

if-chain descending (286) → switch descending (286) → switch ascending
(250, chain matches) → break + single return 1 (191) → case-8 p3 fix
(160) → nested `switch (arg1)` for 0xB (161, reverted). Permuter not
run: score ≫ 5.

## Question for Claude

Is the out-of-line float-store placement (0x6B8-0x720) reachable from any
legal C shape, or — like P25's delay-slot theft — is this a case where
mwcc's scheduler needs the blocks expressed differently (e.g. the float
guards as a shared helper macro with goto, or the `== 3` test written as
`if (sel < 3 || sel > 3)`)? Best C reproduces every statement the original
clearly contains; only block order resists.
