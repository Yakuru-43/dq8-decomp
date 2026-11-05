// range: 0x36EE40 0x36EED0
#include "common.h"

s32 func_00370500(void);
void func_00133CB8(char *dst, char *src);
extern char D_003D4FE8[];
extern char D_003D4FF0[];
extern char D_003D4FF8[];

char *func_0036EE40(char *dst, s32 flag) {
    char *ret;

    if (func_00370500() != 0) {
        if (flag == 0) {
            func_00133CB8(dst, D_003D4FE8);
            ret = dst + 1;
        } else {
            func_00133CB8(dst, D_003D4FF0);
            ret = dst + 2;
        }
    } else {
        func_00133CB8(dst, D_003D4FF8);
        ret = dst + 2;
    }
    return ret;
}
