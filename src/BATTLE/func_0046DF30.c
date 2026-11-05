// range: 0x46DF30 0x46DFF0
#include "common.h"

extern void func_1340C0(char *, char *);
extern s32 func_133F78(s32, char *);

s32 func_0046DF30(char *arg0, char *arg1, s32 *arg2, s32 arg3) {
    char buf[0x100];
    s32 count;
    s32 i;
    char *entry;

    count = 0;
    func_1340C0(buf, arg1);
    for (i = 0; i < 24; i++) {
        entry = arg0 + (i << 5);
        if (M2C_FIELD(entry, s8 *, 0x2A29) != 0) {
            if (func_133F78(M2C_FIELD(entry, s32 *, 0x2A20), buf) == 0) {
                arg2[count] = M2C_FIELD(entry, s32 *, 0x2A1C);
                count += 1;
                if (count == arg3) {
                    break;
                }
            }
        }
    }
    return count;
}
