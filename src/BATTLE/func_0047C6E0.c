// range: 0x47C6E0 0x47C730
// auto: m2c draft, verified byte-exact
#include "common.h"

int func_00461200(char *);
s32 func_00472620(s32);                             /* extern */
char *func_16D5B0(s32, s32);                        /* extern */

typedef struct {
    char pad0[0x50];
    s32 unk50;
} S_arg2;

s32 func_0047C6E0(s32 arg0, s32 arg1, S_arg2 *arg2) {
    char *temp_v0;

    temp_v0 = func_16D5B0(arg0, func_00472620(arg2->unk50));
    if (temp_v0 != NULL) {
        func_00461200(temp_v0);
    }
    return 0;
}
