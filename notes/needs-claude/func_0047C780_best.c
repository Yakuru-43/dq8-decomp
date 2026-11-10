// range: 0x47C780 0x47C880
#include "common.h"

typedef struct {
    char pad0[0x50];
    s32 unk50;
    s32 unk54;
    s32 unk58;
} Target;

s32 func_133F78(s32, M2C_UNK *);                        /* extern */
s32 func_1F96E0(s32, s32);                              /* extern */
s32 func_2C7A50();                                      /* extern */
void func_0047C880(s32, s32);                           /* extern */

extern M2C_UNK D_00484A00 __attribute__((section(".data")));
extern M2C_UNK D_00484A08 __attribute__((section(".data")));

s32 func_0047C780(s32 arg0, s32 arg1, Target *arg2) {
    s32 entry;
    s32 actor;

    if (arg2->unk50 == 0) {
        return 1;
    }
    if (arg2->unk54 == 0) {
        return 1;
    }
    entry = func_2C7A50();
    if (entry == 0) {
        return 1;
    }
    actor = func_1F96E0(entry, arg2->unk58);
    if (func_133F78(arg2->unk50, &D_00484A00) != 0) {
        if (func_133F78(arg2->unk50, &D_00484A08) != 0) {
            return 0;
        }
        func_0047C880((actor != 0) ? actor : entry, 0);
        return 0;
    }
    func_0047C880((actor != 0) ? actor : entry, 1);
    return 0;
}
