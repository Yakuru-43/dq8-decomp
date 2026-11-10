// CLASS structural score=29 (29 words differ, 184 vs 184 bytes)  [best attempt]
// range: 0x475E10 0x475ED0
#include "common.h"

typedef struct {
    char pad0[0xBC];
    s32 unkBC;
    s32 padC0;
    s16 unkC4;
    char padC6[0x2E];
    f32 unkF4;
    f32 unkF8;
} S_arg1;

u32 func_16D5B0(void *, s16);                         /* extern */
void func_0046EBA0(void *);                           /* extern */
void func_00470CE0(u32, f32);                         /* extern */

s32 func_00475E10(void *arg0, S_arg1 *arg1) {
    u32 found;
    f32 sum;
    s32 count;

    found = func_16D5B0(arg0, arg1->unkC4);
    if (found == 0) {
        func_0046EBA0(arg1);
        return 1;
    }
    sum = arg1->unkF4 + arg1->unkF8;
    if (sum <= 1.0f) {
        arg1->unkF4 = sum;
    } else {
        arg1->unkF4 = 1.0f;
    }
    if (arg1->unkF4 < 0.0f) {
        arg1->unkF4 = 0.0f;
    }
    func_00470CE0(found, arg1->unkF4);
    count = arg1->unkBC;
    if (count >= 0) {
        arg1->unkBC = count - 1;
    } else {
        func_0046EBA0(arg1);
    }
    return 0;
}
