// range: 0x350200 0x350330
#include "common.h"

s32 func_0012D4C0(s32);
void func_0016B5F0(char *, s32, s32);
void func_0016B6F0(char *, s32, s32);
s32 func_003501D0(void *);
s32 func_00350330(s32 *);

void func_00350200(char *arg0, char *arg1) {
    s32 *rec;
    s32 i;
    s32 n;

    n = M2C_FIELD(arg0, s32 *, 4);
    if (n >= 7) {
        n = 7;
    }
    if (n <= -7) {
        n = -7;
    }
    func_0012D4C0(n);
    func_0012D4C0(n + M2C_FIELD(arg0, s32 *, 0x18));
    func_003501D0(arg0);
    i = 0;
    do {
        rec = (s32 *)(arg0 + (i * 0xA4) + 0x19A4);
        if (func_00350330(rec) != 0) {
            func_0016B5F0(arg1, 2, *rec);
        }
        i++;
    } while (i < 2);
    i = 0;
    do {
        rec = (s32 *)(arg0 + (i * 0xA4) + 0x19A4);
        if (func_00350330(rec) != 0) {
            func_0016B6F0(arg1, 2, *rec);
        }
        i++;
    } while (i < 2);
}
