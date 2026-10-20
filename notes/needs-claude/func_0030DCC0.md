# func_0030DCC0 (P40) — needs-claude

- **Binary/size:** SLES_539.74, 0x30DCC0, 3984 B (range 0x30DCC0–0x30EC50,
  two tail nops; `// range:` end = funcdb end per P17 rule).
- **TU:** dq_player_ai.cpp. 996 instructions, 38 callees, 15 stack locals +
  6 buffers. Largest pilot function so far.
- **Result:** NC — best C (uncommitted, `src/SLES_539.74/func_0030DCC0.c`,
  copied from the session; m2c draft regenerable with
  `.venv/bin/m2c --valid-syntax --globals used --no-cache -t mips-gcc-c
  -f func_0030DCC0 asm/SLES_539.74/game_30D7C0.s`) never compiled:
  `M2C_FIELD(x, void *, …)` derefs void*, the 64-bit call results and the
  two `adda.s`/`madd.s` chains need real types. 2 scored runs, no compile.

## What it does
Player-AI action picker around the `D_00453D10` table (same Table as P24:
`base = D_00453D10 + *(0x2C)`, records are 0x20 B, child index at 0x4/0x6/0x8/0xA
as `s16`, `base + (idx << 5)` descent — the P24 walk again).

1. `table = func_0030EFB0(D_00453D10)`; null → return. `rec =
   func_0030EF80(D_00453D10, arg1)`; `pool = func_0029C600(arg0) result's
   sibling: v0 = arg0->0xA94; pool = v0 + 0xE0` (the `lw v0,0xA94` feeds the
   `addiu s7,v0,0xE0` **delay slot** of `jal func_0029C600` — store BEFORE
   the call reads it, P21-style); `func_0030EF10(&spD40)`.
2. Outer walk `while (rec->4 > 0)`: `sel = (rec->2 > 0) ? func_0030F700 : 1`;
   gate `f20 = (f32)rec->0x18 / 10000.0f; if (func_00328110(&D_003E1160) <= f20)`
   → act dispatch (act = `lh 4(rec)`): 1/2 → the big pool-fill block;
   3 → early return if `arg0->0x24 (f32) > (f32)rec->0x16`;
   else the `lh 0(rec) > 0` shared-return block (EBF8).
3. Act 1/2: `entry1F8 = func_0030EEF0(D_00453D10, rec->6)` (assert 0x4CB),
   `func_0030F850(A94, arg0+0x1EC, arg0->0x1E8, entry1F8, arg1)`, then
   `for (index = 0; index < arg0->0x1EC; index++)`:
   `id = M2C_FIELD(arg0 + index*4, s32, 0x1F0)`; `entry = func_001FFBA0(&D_0042CDB0, id)`
   (assert 0x4D9); `count100 = func_0035BDC0(A94, entry->f0)` (64-bit,
   `sq → 0x100(sp)`, `*10` computed as `(n<<2)+n<<1` via `sq 0xE0(sp)`);
   `D_003E116C = (s32)count100`; init 32 cands: `for (p=sp+0x7C0; p<sp+0xD40;
   p+=0x2C) func_0029C5D0(p)`.
4. Flag decode from `entry->f1` (3→1B0+16F-if-f2==1&&f20&0x4000, 2→1C0,
   1→1A0, 4→1D0) and `entry->f2` (3/5→170, 2/4→180, 4/5→190). Byte flags at
   sp+0x120/0x140/0x150/0x16F/0x170…0x1D0.
5. Node walk (`for (node = list->0x18; node; node = node->0x18)`,
   list = `arg0->0xA8C`): four flag tests (`func_0035E590`, `func_00297090`),
   hits → append candidate to `sp + cnt*0x2C + 0x7C0` (func_0029C600 init,
   id, node substruct `lh 0xC/0x10/0x12` into fC/f4/f8, node into f10,
   `(arg0+index*2)` via `sq 0xF0(sp)` then `lh 0x500/0x688` into f1C/f20).
   Exit-walk: `(170||1A0) && cnt>0`.
6. `cnt > 0`: 42×16 B copy pool→`sp+0x520` (P26 countdown idiom); then
   `for (fp = 0; fp < cnt; fp++)`: writes to pool (`0`→id, `0x288`→entry,
   8/0xC→entry f1/f2, 0x10/0x14→cand f4/f8), fF∈{2,0x42} → `cand->0x29` chain
   (D34 == `func_00297090(node->0x1C->0x1C)`), pool+0xE0 block + assert
   strings, 42×16 B copy to `sp+0x280`, `keep = func_0029AC20(&D_0042CDB0, A94,
   2) & 0xFF`, `func_0030ECD0(pool+0xE0, sp280)`, the t1/t0 secondary list walk
   (0xA8C again, `lhu 0x10 != 0xFFFF`, `lbu 3`, flag180/190 tests → v1),
   `(keep && v1)` → block_129: `func_00131188(sp200,0,0x80)`,
   `func_0030F3D0`, `d0 = func_00356DE0(D_00453D10, rec->0x14)` (assert 0x5BA),
   `func_00329400/0x3293C0` queue loop (`buf200[slot*0x200]` guard,
   **8-arg** `func_0030D600(spEB8, spD40, d0+4, *d0, t0=A8C, t1=A90,
   t2=cand->0x10, t3=pool+0xE0)`), `func_0030ECB0` f32 ≠ 0 → cand->0x24 +=,
   `func_00329A60/AFA0` score chain (`< 2` → B4B0→359CF0(&D_00421AD0)→B4A0→
   0x342850 `lhu 0x24 & 2` → 120 flag), id∈{D_003E1168→1, 0x85&flag→2},
   cand->0x18 = score; `func_00329330/0x30ECD0/0x30EC70`; float finalize:
   `cand->0x24 -= (f32)count100 / 100.0f; if (f29) *= 2;` then D38/150/1168
   ladder → `*= D_003DF440` or `*= D_003DF390`; then the **id chain**
   0x16A/0x149/0x20F/0x15E (f = 297090/2970A0; `> D_003DF3B4` → ×0.5;
   `> 0.5` → nothing; else ceil(count/8), `f2 = D_003DF3BC*(f32)(x − count*10)
   + 1.0` **via adda.s/madd.s**, clamp [1.0, D_003DF440], ×=) and
   0x161/0x211 (297060 pair − 297050 vs ceil(count/16)+1 or /8, min,
   `f1 = D_003DF3A8*(f32)a0 + 1.0` **adda.s/madd.s**, clamp ≤ D_003DF444,
   a0<=0 → 0.5, ×=).
7. After the candidate loop: flag16F → scoring pass over cands (`f28==0` →
   `+0x100000`; `func_0030B890(node->0x1C, 8)==0` → `+0x80000`; 0x40000 →
   `+0x40000`; `f18 >= func_00201760(node->0x1C, 0)` → `+0x20000` else
   `+= 0xFFFF − (f − f18)`; best via `0x7D4` = cands[best]->0x14, P39 family)
   else the plain accept-all loop; both end `func_0030EC50(cand, arg0)` &&
   `!(cand->0x24 <= (f32)rec->0x16)` → `func_0029C560`.
   `cnt <= 0` or scoring done → `sp1E0++` (index reload via `lw 0x1E0(sp)`
   three times — the loop variable lives on the stack).

## What blocks a match (why needs-claude)
- Frame is `sp − 0xEC0` with **sq/lq 64-bit pairs** at 0xB0/0xC0/0xD0/0xE0/
  0xF0/0x100/0x110 (call results of `func_00297060/00356DE0/0035BDC0/0030EFB0`
  returned in `$v0:$v1`) — needs `s64`-typed locals declared early; the pair
  arithmetic (`lq; sll; addu; sll` = ×5 then ×10, `subu a0, a0, v1`) has to
  come from integer math on the low half of an s64, not float.
- Two `adda.s`+`madd.s`+`c.lt/c.le` clamp chains (0xEB0C, 0xE934) — the P39
  32-bit-const story; mwcc only emits accumulator instructions for a specific
  source shape (fused `+=` with a float accumulator).
- The 8-argument `func_0030D600` call (a0–a3 + t0–t3) and the 5-arg
  `func_0030F850` must be declared exactly, plus `func_0029AC20`'s result
  `& 0xFF`-ed into s6 before `beqz`.
- Same block-placement/delay-slot family as P14/P15/P25/P30/P31/P36: the
  E9EC/EA44/EA9C weave, the `andi s6,v1,0xFF` in the 297090 delay slot at
  0xE3F8, and `beq a1,a0` chains with `-1`/`0xFFFF` seeds will not survive a
  first hand draft.

## Tried
- m2c (`-t mips-gcc-c --valid-syntax`) from the region file — full skeleton,
  two M2C_ERROR (adda.s/madd.s). autodecomp last = `m2c` (compiled, never
  matched).
- Hand rewrite: typed structs (Entry/Cand), P26 pointer-walk for both
  42×16 B copies, P21 delay-slot load-before-call for the `0xA94` read,
  guard-clause walks. Did not compile (void* derefs, s128 math); stopped per
  rule 9 with 2 scored runs (both compile failures → NC).

## Question for Claude
The three 64-bit-returning callees (`func_0035BDC0`, `func_00356DE0`,
`func_00297060`) and `table` (`func_0030EFB0`) are stored with `sq` and read
back with `lq` — which `s64`/pair local declaration order reproduces
0xB0–0x110, and does the ×5/×10 (`(n<<2)+n<<1`) want `count100 * 10` on an
`s64`? Also: what is the source shape for the two `adda.s/madd.s` clamp
chains (`acc = 1.0f; acc += k * (f32)x;` vs a `for` over terms)?
