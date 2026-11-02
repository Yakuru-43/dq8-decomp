# func_0015AFF0

CLASS structural score=104 (102 words differ, 412 vs 404 bytes) — best of 6 attempts.

- asm size: 404 (queue size 416 incl. padding); `nonmatching func_0015AFF0, 0x194`
  in `asm/SLES_539.74/game_15AEF0.s`; twin (near-identical loop) is
  `func_0015AEF0` in the same file; layout types already exist in
  `src/SLES_539.74/func_0015B190.c` (FuncMgr/FuncNode, but note its
  `pad_1C4[0x14]` vs my `[4]` — check which one verify accepts; my function
  provably uses entries=0x1C8, capacity=0x1CC, count=0x1D0, prefix=0x1E4).

## What it does
Pops a node from the free pool (`count < capacity` → `count++`, `node =
entries[old count]`), debug-prints if the pool was empty (`D_003C2130`) and
when `D_003E0294 != 0` (prints count/capacity, `D_003C2098`), builds the
search string (`strcpy(buf, name)` + `strcat(buf, &mgr->0x1E4)` when the
prefix byte at 0x1E4 is set), hashes it `h = ((h << 8) + c) % 101`, walks
`mgr->buckets[h]` calling `func_00133F78(str, cur->self->name)` (strcmp); on
a match sets `D_003EDE98 = 1`, `func_00134750(&D_003EDE99, found->name,
0x20)` (strncpy), `DebugPrintf(D_003C2110, name)`; always returns the popped
`node`. Frame: `addiu sp, -0xD0`, ra at 0x40 (sd), s3/s2/s1/s0 saved via sq,
buffer at 0x50..0xD0 (0x80 bytes).

## The problem (register allocation, not logic)
Original saves only ra + s0..s3: s0=str, s1=node, s2=name, s3=mgr **and then
cur** (the bucket load `lw $s3, 0x30($v0)` reuses mgr's register), and keeps
`found` in **$v0** — the natural loop exit emits `daddu $v0, $zero, $zero`
because the bnel delay slot `lw $v0, 0($s3)` clobbered it; the beql (break)
delay slot reloads `lw $v0, 0($s3)` = found. My C always got 5 callee-saved
registers (mine: ..., s3=cur, s4=mgr kept separate) → frame 0xE0 vs 0xD0,
buf at 0x60 vs 0x50, and the whole tail shifted; 412 bytes vs 404 (two
extra trailing nops).

## What I tried
1. Draft as in `func_0015AFF0_best.c` (in this dir) — 5 regs.
2. Removed the `slot` temp (inline bucket load into the for-init) — no change.
3. `FuncNode *self = cur->self` local in the loop body — worse (6 regs, 420).
4. Declaration-order idiom (str, node, cur first) — no change.
5. `for` → `while` loop with `cur = mgr->buckets[hash]` outside — no change.
6. `tools/permute.py func_0015AFF0 --run 300` — crashes: FileNotFoundError
   'cpp' (needs a C preprocessor on PATH; this box has none — check whether
   wibo ships one or permute needs a wrapper).
   MH2 catalogue not consulted (structural, not a near miss; time budget).

## Hints for the fix
Something about the C makes CW think `mgr` is live where it isn't, or makes
`found` longer-lived than the original's $v0. Ideas: pass `mgr->buckets[hash]`
result through a `FuncNode **`/cast spelled like the twin; the original might
test the loop end with the strcmp result and re-derive found (`if
(strcmp==0) {found = cur->self; break;}` may need `cur` to be *the same
variable* as the bucket cursor AND found assigned only inside the if — tried);
or `str` might not be a local (arg reused via s0 differently); or the prefix
block is `if (*mgr->name2)` shape with a struct field typed differently so
`s3` dies before `cur` is defined. Compare against the already-matched twin
style in `func_0015B190.c` (which got the same loop with u8 hash + `for`
form matching there).

Best C: `notes/needs-claude/func_0015AFF0_best.c` (also left untracked at
`src/SLES_539.74/func_0015AFF0.c` — deletion blocked by tool policy; delete
before integrating this range).
