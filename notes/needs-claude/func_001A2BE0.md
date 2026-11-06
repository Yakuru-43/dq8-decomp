# needs-claude: func_001A2BE0

CLASS structural score=28 (20 words differ, 196 vs 164 bytes) — best attempt
(template inline-helper form, 2 attempts; identical score with head `Node *`
or `u32`).

Size 176 (0x1A2BE0-0x1A2C90), `asm/SLES_539.74/game_1A2990.s`. Fourth member
of the list-push pool family: func_001A2990 / func_001A2AA0 / func_001A2B30
(see their notes; same file). Best C (also in
notes/.scratch_w1/func_001A2BE0_best_w1.c): the MATCHED template
src/SLES_539.74/func_001A3900.c's `node_add` **minus** the `s32 *index`
output, caller:

```c
static inline Node *node_add(NodePool *pool) {   /* for i<count, goto found,
    n = NULL; found: if (n == NULL) return NULL; tail/head append; return n; } */
void func_001A2BE0(NodePool *pool, const f32 *pos, s32 time) {
    Node *n = node_add(pool);
    if (n != NULL) {
        n->state = 35;
        func_0010ADF8(n->pos, pos);   /* a1 passed straight through */
        n->time = time;
    }
}
```

Structs: pool `items` 0x00 / `count` 0x04 / `head` 0x30 / `tail` 0x34
(`char pad8[0x28]`); node 0x50 bytes: `state` 0x00, 4 floats at 0x10 (copied
by `func_0010ADF8(f32 *, const f32 *)`, cf. func_001A3750.c), `time` 0x20,
`next` 0x4C.

## What matched vs what didn't
The loop prologue, guard 1 (`beql $s0,$zero,+A; daddu $s0,$zero,$zero` peel),
tail check (`beqz+nop+sw`), `sw n,tail; sw $zero,next(n)`, guard 2
(`beqz+nop`), and the whole guard-2 body incl. `sw $v0,0($s0)` in the `jal`
delay slot ALL matched first try. First real diff is at +0x28 and the only
two encoding diffs are the same family pair as the twins' notes:
1. loop found test: original `beql $v1,$zero,.L001A2C28` + `sw $zero,0x4C($s0)`
   in the (annulled-on-fallthrough) delay slot; mine `beqz $v1,<far>` with the
   store tail-placed.
2. head check: original `beql $v1,$zero,+2` + `sw $s0,0x30($a0)` in the delay
   slot; mine `beqz+nop` and the store laid out cold after the epilogue.
Diffs from +0x90 are CW cloning the loop + found path to serve those two
cold blocks (~32 B too long).

## Notes on this member vs the twins
- No `*index = i` (so `i` dies at `found:`) and no divbyzerocheck body — and
  dropping `*index` moved the score from the twins' 34 to 28: everything up to
  the head check is byte-exact now. The two beqls are all that is left.
- Checked against notes/idioms.md "Free-slot search + head/tail list append"
  (its OPEN list at the bottom names exactly this shape: "the siblings whose
  original uses `beql` for every one-instruction if") and
  notes/needs-claude/func_001A6710.md — that note tried goto-vs-return,
  two one-level inlines, ternary, -O2/-O3/-O4/-O4,p/-O4,s/-O3,s, C++,
  divbyzerocheck on/off, all with no change: "not C shape".
- MH2 Index consulted (rule 8): no branch-likely rule; the catalog says its
  own MWCC never emits branch-likely (line 25) and files full of `beql` are
  "GCC libraries, stay assembly (Not from C)" (line 337) — opposite situation
  from ours, where b151 *does* emit `beql` elsewhere (guard 1 above matched as
  beql). The compiler-build-sweep's positive b119 case
  (func_00291950) has the reverse sign: original has NO branch-likely where
  b151 insists on them. This class (original has *more* beql than b151 emits)
  has not been tried against the other builds; try_match supports `--ver`,
  verify.py pins b151.

## Tried here (2 attempts, both score 28)
1. Template helper verbatim minus `*index`, `if (pool->head == NULL)
   { pool->head = n; }`.
2. `head` typed `u32` with `== 0` / `(u32)n` (the twins' note's untried idea;
   no change — the tail check stays `beqz+nop` and the head stays cold, so CW
   is not keying on the type here).
