// range: 0x36CCB0 0x36CD90
#include "common.h"

s32 func_0022A880(s32 value);
void func_002E4CF0(s32, char *);
s32 func_00370500(void);
void func_00133CB8(char *dst, char *src);
void DebugPrintf(char *, char *);
extern char D_003D4EB8[];
extern char D_003D4EC0[];
extern char D_003D4EC8[];

void func_0036CCB0(char *dst, s32 value, s32 count) {
    char text[0x40];
    s32 digits;
    s32 i;

    if (dst != 0) {
        digits = func_0022A880(value);
        dst[0] = 0;
        if (0 < count) {
            count = count - digits;
            for (i = 0; i < count; i++) {
                if (func_00370500() == 0) {
                    func_00133CB8(dst, D_003D4EB8);
                } else {
                    func_00133CB8(dst, D_003D4EC0);
                }
            }
        }
        func_002E4CF0(value, text);
        func_00133CB8(dst, text);
        DebugPrintf(D_003D4EC8, dst);
    }
}
