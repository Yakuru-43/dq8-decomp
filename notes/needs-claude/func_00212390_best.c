// range: 0x212390 0x212430
// BEST attempt: CLASS structural score=17 (16 words, 148 vs 152 B).
// The separate-variable variant (also saved here, bottom) is the one that
// BREAKS the cursor fold for def1 — see the note.
#include "common.h"

typedef struct {
    s32 type;
    s32 val;
} Item;

extern char *D_003E0908;
extern s32 D_003E0918;
extern char *D_003E0944;

u32 func_00166760(Item *);
s32 func_001667C0(Item *);
s32 func_00133F78(char *, u32);
void func_002127B0(char *, Item *);

s32 func_00212390(Item *arg0) {
    u32 handle;
    s32 count;

    handle = func_00166760(arg0);
    if (handle == 0) {
        return 0;
    }
    arg0 = arg0 + 1;
    if (func_00133F78(D_003E0908 + 0x3F4, handle) != 0) {
        return 0;
    }
    count = func_001667C0(arg0);
    arg0 = arg0 + 1;
    if (count != D_003E0918) {
        return 1;
    }
    M2C_FIELD(D_003E0944, u8 *, 0x70) = 1;
    func_002127B0(D_003E0944 + 0x60, arg0);
    M2C_FIELD(D_003E0908, u128 *, 0x430) = M2C_FIELD(D_003E0944, u128 *, 0x60);
    return (s32)D_003E0908;
}

// VARIANT (score=29, all instructions present, scheduling off): replaces the
// two `arg0 = arg0 + 1` mutations with a separate-variable chain, which stops
// CW folding def1 into the uses:
//
// s32 func_00212390(Item *arg0) {
//     Item *item1;
//     Item *item2;
//     u32 handle;
//     s32 count;
//
//     handle = func_00166760(arg0);
//     if (handle == 0) { return 0; }
//     item1 = arg0 + 1;                 // survives: daddu $a0,$s0 + addiu $s0,$s0,8
//     if (func_00133F78(D_003E0908 + 0x3F4, handle) != 0) { return 0; }
//     count = func_001667C0(item1);
//     item2 = item1 + 1;                // still folds: addiu $a1,$s0,8, nop delay
//     if (count != D_003E0918) { return 1; }
//     ... (same tail)
// }
