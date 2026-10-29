CLASS reorder+register score=2 (2 words differ, 192 vs 192 bytes)

# func_001C0DD0 (SLES_539.74, 0x001C0DD0, 192 B)

`make split` gives this region **no file**: `game_1C0AE0.s` ends at 0x1C0DCC
(3 nops) and the next file starts at 0x1C0E90 — so `show_func.py`/`permute.py`
can't find a glabel. Disassemble with
`.venv/bin/python -I notes/.scratch_w1/disfunc.py func_001C0DD0 0x001C0DD0 0xC0`.

## What it does
Dispatch node: `if (o->kind == 1)` the field at +0x04 is a float converted
with `cvt.w.s`, else a raw int; both arms load `a2 = o->field_0C` (the float
arm's load sits in the `b` delay slot). Call `func_001ABB60(&D_00411ED0, a1,
a2, buf)` with `f32 buf[3]` at 0x20(sp) (`a3 = addiu sp,0x20` in the jal
delay slot). `beqz v0` (nop slot) to the shared epilogue on call failure;
then three unrolled `{s32 type; char *ptr;}` stores at 0x10/0x18/0x20:
`if (type == 3) *(f32 *)(ptr + 4) = buf[i]`. `addiu v0,zero,1` at entry is
the compare constant for `kind == 1` (v0 = call result is the return value).
Slot 0/1 tests are `beq` to an out-of-line body that jumps **back** to the
next test (`addiu a1,s0,0x10/0x18` in each beq delay slot, body loads
`0x4(a1)`); slot 2 is `bne`-away with its store inline, loading `0x24(s0)`
directly. `buf[1]`'s `lwc1` sits in the test-1 block, `buf[2]`'s in the
test-2 `bne` delay slot, `buf[0]`'s in body 0 after the `lw`.

## Best attempt (score 2, 4 attempts) — everything matches EXCEPT:

```
  +038  lui         $a0, 0x0               lui         $a0, 0x41        (reloc, ignore)
* +03C  addiu       $a3, $sp, 0x20         addiu       $a0, $a0, 0x1ED0
  +040  jal         func_000000            jal         func_1ABB60      (reloc, ignore)
* +044  addiu       $a0, $a0, 0x0          addiu       $a3, $sp, 0x20
```

The `%lo` addiu of `&D_00411ED0` must come right after the `lui` (chain
contiguous), and `addiu a3,sp,0x20` must fall into the jal's delay slot. Mine
interleaves them. All 46 other words are byte-identical.

The winning C structure (keep it; the previous session's draft was score 13):

```c
// range: 0x1C0DD0 0x1C0E90
#include "common.h"

typedef struct Slot1C0DD0 {
    /* 0x00 */ s32 type;
    /* 0x04 */ char *ptr;
} Slot1C0DD0;

typedef struct {
    /* 0x00 */ s32 kind;
    /* 0x04 */ union {
        f32 as_float;
        s32 as_int;
    } field_04;
    /* 0x08 */ s32 field_08;
    /* 0x0C */ s32 field_0C;
    /* 0x10 */ Slot1C0DD0 out[3];
} S_1C0DD0;

typedef struct {
    s32 _pad[4];
} S_D_00411ED0;

extern S_D_00411ED0 D_00411ED0;

s32 func_001ABB60(s32, s32, s32, f32 *);

s32 func_001C0DD0(S_1C0DD0 *obj) {
    f32 buf[3];
    f32 val1;
    f32 val2;
    s32 a1;
    s32 a2;
    s32 result;
    f32 *bp;
    Slot1C0DD0 *sl;

    if (obj->kind == 1) {
        a1 = (s32)obj->field_04.as_float;
        a2 = obj->field_0C;
    } else {
        a1 = obj->field_04.as_int;
        a2 = obj->field_0C;
    }
    bp = buf;
    result = func_001ABB60((s32)&D_00411ED0, a1, a2, bp);
    if (result != 0) {
        sl = obj->out;
        if (sl->type == 3) {
            *(f32 *)(sl->ptr + 4) = buf[0];
        }
        sl = obj->out + 1;
        val1 = buf[1];
        if (sl->type == 3) {
            *(f32 *)(sl->ptr + 4) = val1;
        }
        val2 = buf[2];
        if (obj->out[2].type == 3) {
            *(f32 *)(obj->out[2].ptr + 4) = val2;
        }
    }
    return result;
}
```

## Tried (all leave the same score=2 swap)
1. `void *` param + `&D_00411ED0`, `f32 *` param + `buf`.
2. `s32` param + `(s32)&D_00411ED0` (per mh2 §Arguments loaded in another
   order, "An address argument computed first, or last in the call's delay
   slot": *`(s32)&D_...` to an int parameter adds the %lo one slot earlier
   than to a pointer parameter* — it did not move it here).
3. Both address args int: `s32` params, `(s32)&D_00411ED0`, `(s32)buf`.
4. Named buffer local `f32 *bp = buf;` just above the call
   (mh2 §Placement line 155 "locals then the call").

Untried ideas: `bp = &buf[0]` / `buf + 0` spellings; `a1`/`a2` declaration
swap; static callee tricks; the permuter (needs a hand-built target.o —
assemble the 48 words with real `lui %hi(D_00411ED0)`/`%lo`/`jal
func_1ABB60` relocations so objdump output matches the compile side, as
notes/.scratch_w1/permute_setup.py did for func_00141750).

Try with: `tools/try_match.py src/SLES_539.74/func_001C0DD0.c func_001C0DD0
0x001C0DD0 --show -- -O3 -Isrc`

Siblings for style: src/SLES_539.74/func_001C1060.c (twin of the kind==1
cvt arm), func_001C1330.c (same D_00411ED0 call family).

Tried by Qwen factory-1, 2026-10-28, 4 attempts / ~25 min.
