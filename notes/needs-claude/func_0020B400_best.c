// best attempt for func_0020B400 (score 2, see func_0020B400.md)
// range: 0x20B400 0x20B4B0
#include "common.h"

extern void func_00133CB8(char *dst, char *src);
extern void func_001339E0(char *dst, char *fmt, ...);

extern char D_003C7590[];
extern char D_003C7598[];
extern char D_003C75B8[];
extern char D_003C7620[];

typedef struct {
    s32 level;
} TagInfo;

/* Appends a bucket word and the decimal value of value to str. */
void func_0020B400(TagInfo arg0, char *str, s32 value) {
    char val[8];
    char flag[8];

    flag[0] = 0;
    if (value < 10) {
        func_00133CB8(flag, D_003C75B8);
    } else {
        if (value < 100) {
            func_00133CB8(flag, D_003C7590);
        }
    }
    func_001339E0(val, D_003C7598, value);
    func_00133CB8(flag, val);
    func_001339E0(str, D_003C7620, flag);
}
