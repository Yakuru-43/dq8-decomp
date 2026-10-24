// range: 0x296870 0x296930
#include "common.h"

typedef struct {
    char pad0[0x590];
    s32 unk590[6];
    s32 unk5A8[6];
    s32 unk5C0[6];
} S_arg0;

M2C_UNK func_00292960(S_arg0 *);                     /* extern */
M2C_UNK func_00291170(S_arg0 *);                     /* extern */
M2C_UNK func_00292460(S_arg0 *, s32);                /* extern */
M2C_UNK func_00291050(S_arg0 *);                     /* extern */
M2C_UNK func_002912C0(S_arg0 *);                     /* extern */
void func_00291670(S_arg0 *);                        /* extern */
s32 func_002915F0(S_arg0 *, u8);                     /* extern */

s32 func_00296870(S_arg0 *arg0) {
    func_00292960(arg0);
    func_00291170(arg0);
    func_00292460(arg0, 8);
    if (func_002915F0(arg0, 0) <= 0) {
        func_00291670(arg0);
    }
    func_00292460(arg0, 0x40000);
    if (func_002915F0(arg0, 0) <= 0) {
        func_00291670(arg0);
    }
    func_00291050(arg0);
    if (func_002915F0(arg0, 0) > 0) {
        func_002912C0(arg0);
        return 1;
    }
    return 0;
}
