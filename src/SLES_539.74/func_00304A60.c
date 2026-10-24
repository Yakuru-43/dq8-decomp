// range: 0x304A60 0x304AD0
#include "common.h"

typedef struct {
    char pad0[0x4150];
    s32 amount; /* +0x4150 */
} S_arg0;

/* Adds delta to the amount, clamped to 0..0x7FFFFFFF. */
void func_00304A60(S_arg0 *arg0, s32 locked, s32 delta) {
    s64 value;

    if (locked == 0) {
        value = (u32)(arg0->amount + delta);
        if (value < 0) {
            value = 0;
        }
        if (value > 0x7FFFFFFF) {
            value = 0x7FFFFFFF;
        }
        arg0->amount = (s32)value;
    }
}
