# func_001C9EC0 — needs-claude

CLASS structural score=5 (5 words differ, 68 vs 68 bytes)
`DIFF at +0x10: mine 14620004 orig 54620004` (try_match `-- -O3`, ver 3.0.1b151)

Size: 0x44 (68 B, range 0x1C9EC0 0x1C9F10), asm/SLES_539.74/game_1C9960.s.

## What it does
Tagged value at `arg0`: word 0 = tag, word 4 = value. If tag != 1 the value is
used as-is; if tag == 1 the value is a pointer and the real value is
`(s32)*(f32 *)(value + 4)` (`lwc1`/`cvt.w.s`/`mfc1`). Then
`func_001A2190(value)` is called (frame `addiu $sp,-0x10` + `sd/ld $ra,0($sp)`),
and the function returns `result != 0` laid out as
`beql $v0,$zero,<epi>; daddu $v0,$zero,$zero` + `addiu $v0,$zero,1` fall-through.

## Shape of the diff (the whole story is one register)
The original loads the value **into `$a0` over the base**:
`bnel $v1,$v0,.L; lw $a0,4($a0)` (delay slot), the float path reads
`lwc1 $f0,4($a0)` off the value itself and `mfc1 $a0,$f0` back into `$a0`; the
`jal` delay slot is `nop`. Mine (all four attempts) loads into `$a1`, does
`lwc1 4($a1)`, `mfc1 $a1`, and copies `daddu $a0,$a1,$zero` in the `jal` delay
slot; the first branch comes out plain `bne` instead of `bnel`. Same size,
same schedule everywhere else. So CW coalesced `lw $a0,4($a0)` (dst==src, base
dies at the load) in the original but not in my C.

## Best C (attempt 4, score 5)
```c
// range: 0x1C9EC0 0x1C9F10
#include "common.h"

M2C_UNK func_001A2190(char *);

s32 func_001C9EC0(char *arg0) {
    char *v;
    s32 tag;

    v = arg0;
    tag = *(s32 *)v;
    v = *(char **)(v + 4);
    if (tag == 1) {
        v = (char *)(s32) * (f32 *)(v + 4);
    }
    if (func_001A2190(v) != 0) {
        return 1;
    }
    return 0;
}
```

## What I tried
1. `s32 v` loaded first, `if (*(s32*)arg0 == 1)` re-read through the base,
   `return func(v) != 0;` → 60 B: `bne`, `$a1`+`daddu`, and `sltu $v0,$zero,$v0`
   for the `!= 0` (score 11).
2. Split tag into its own local (`tag = *(s32*)arg0;` before the value load, so
   the base dies after the two loads), `if (func(v) == 0) return 0; return 1;`
   → 68 B but the post-call test inverted: `bnel`+`addiu 1`+fall `daddu 0`
   (score 8).
3. Same as 2 but `char *v` + `(char *)(s32)` casts and callee taking `char *`,
   flipped to `if (func(v) != 0) return 1; return 0;` → post-call test now
   byte-exact (`beql`+delay-`daddu 0`+fall-`addiu 1`), value still in `$a1`
   (score 5). This is the current file.
4. Walked one pointer variable (`v = arg0; tag = *(s32*)v; v = *(char **)(v+4)`)
   hoping to force `lw $a0,4($a0)` — no change, still `$a1` (score 5).

Not tried: `tools/permute.py` fails here — its compile.sh calls `cpp` which is
not on PATH in this worktree (`FileNotFoundError: 'cpp'`). With the diff being
register-only this is exactly what the permuter is for; if `cpp` is made
available, run `permute.py func_001C9EC0 --run 600` first.

Also untried ideas: struct with named fields for the tag/value pair; a union
`{ s32 i; char *p; }` at +4 so the float read is a member of the same local;
`.cpp` + inline member accessors (see notes/idioms.md "Field load CSE'd…" and
"sw v0,N(s0); lw v0,N(s0)" — the non-CSE behaviour there may be what keeps the
base separate in my builds and merges it in the original).

Twins in the queue to check when solved: the plain tail-call tagged packers
were matched this session as func_001C0F40/C10E0/C1240/C1330/C1460 (twin of
src/SLES_539.74/func_001C2900.c); func_001C9EC0 is the call+return-bool variant.
