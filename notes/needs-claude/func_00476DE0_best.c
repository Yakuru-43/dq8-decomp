/* func_00476DE0 (BATTLE, 224 B) — best draft (factory-6, 2026-11-05, ~17:40).
 * NOT matched: CLASS structural score=53 (244 vs 224 B).
 * Dispatch + both bodies now match the original word-for-word; the two
 * `if (D_00421A14 != 0) { call }` guards get sunk out-of-line by CW
 * (bnez + far block + b back) instead of inline beqz-skip, and the return
 * stub gets duplicated. See func_00476DE0.md for the full analysis.
 * Key discoveries: switch written `case 0` then `case 1` gives the
 * original's compare chain order (==1 first) and body layout (B0 first);
 * the counter decrement needs a local to avoid reloading 0xBC.
 */
// range: 0x476DE0 0x476EC0
#include "common.h"

typedef struct {
    char pad0[0xB8];
    s32 unkB8;
    s32 unkBC;
} S_476DE0;

extern void func_00476EC0(M2C_UNK, char *, s32);
extern void func_0046EBA0(S_476DE0 *);
extern s32 D_00421A0C __attribute__((section(".data")));
extern s32 D_00421A14 __attribute__((section(".data")));
extern char D_00484908[];
extern char D_00484918[];

s32 func_00476DE0(M2C_UNK arg0, S_476DE0 *arg1) {
    s32 c;

    switch (arg1->unkB8) {
    case 0:
        if (D_00421A14 != 0) {
            func_00476EC0(D_00421A14, D_00484908, 6);
        }
        if (D_00421A0C != 0) {
            D_00421A0C = 2;
        }
        arg1->unkB8 = arg1->unkB8 + 1;
        break;
    case 1:
        c = arg1->unkBC - 1;
        arg1->unkBC = c;
        if (c > 0) {
            goto end;
        }
        if (D_00421A14 != 0) {
            func_00476EC0(D_00421A14, D_00484918, 4);
        }
        if (D_00421A0C != 0) {
            D_00421A0C = 1;
        }
        func_0046EBA0(arg1);
        break;
    }
end: ;
    return 0;
}
