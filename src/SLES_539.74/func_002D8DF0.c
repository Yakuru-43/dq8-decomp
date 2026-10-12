// range: 0x2D8DF0 0x2D8E70
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

M2C_UNK func_001487A0(s32);                         /* extern */
s32 func_0015F490();                                /* extern */
M2C_UNK func_0022EFF0(char *, char *);              /* extern */
char *func_002D8E70(s32);                           /* extern */

s32 func_002D8DF0(s32 arg0, s32 arg1, char *arg2) {
    s128 *temp_s1;
    s32 temp_v0;
    char *temp_v0_2;

    temp_v0 = func_0015F490();
    temp_s1 = M2C_FIELD(arg2, s128 **, 0x2C);
    temp_v0_2 = func_002D8E70(temp_v0);
    M2C_FIELD(temp_v0_2, s128 *, 0x10)= (s128) *temp_s1;
    func_0022EFF0(temp_v0_2 + 0x20, (char *) temp_s1 + 0x10);
    func_0022EFF0(temp_v0_2 + 0x60, (char *) temp_s1 + 0x50);
    func_001487A0(temp_v0);
    return 0;
}
