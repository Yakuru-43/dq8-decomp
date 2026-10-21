// range: 0x2FE2B0 0x2FE690
#include "common.h"

extern M2C_UNK D_003CFF80 __attribute__((section(".data")));
M2C_UNK func_00131188(char *, M2C_UNK, M2C_UNK);    /* extern */
u32 func_001341D8();                                 /* extern */
char *func_00201F10();                               /* extern */
s32 func_002B22B0(char *);                           /* extern */
s32 func_002E2C70(u16 *, char *);                    /* extern */
s32 func_002E3380(char *, char *);                   /* extern */
M2C_UNK DebugPrintf(M2C_UNK *);                      /* extern */

s32 func_002FE2B0(u16 *arg0) {
    char buf260[0x100];
    char buf160[0x100];
    char buf60[0x100];
    char *name;
    char *text;
    char *tag2;
    s32 count;
    s32 len;
    u16 c;
    u16 d;

    if (arg0 == 0) {
        return 0;
    }
    func_00131188(buf260, 0, 0x100);
    len = func_002E2C70(arg0, buf260);
    if (len <= 0 || len >= 0x100) {
        DebugPrintf(&D_003CFF80);
    }
    name = func_00201F10(0);
    func_001341D8(name);
    func_00131188(buf60, 0, 0x100);
    tag2 = buf160;
    func_00131188(tag2, 0, 0x100);
    count = func_002B22B0(buf60);
    func_001341D8(buf60);
    text = buf160;
    func_001341D8(text);
    if (arg0[0] == 'C') {
        c = arg0[1];
        if (c == '@' && arg0[2] == 'M' && arg0[3] == '=' && arg0[4] == '@') {
            return 1;
        }
        if (c == 'D' && arg0[2] == 'K' && arg0[3] == 'K' && arg0[4] == 'J' &&
            arg0[5] == 'Q' && arg0[6] == 'J' && arg0[7] == 'G') {
            return 1;
        }
        if (*name == 'h' && func_002E3380(buf260, name) == 0) {
            return 1;
        }
        if (0 < count) {
            if (buf60[0] == 'h' && func_002E3380(buf260, buf60) == 0) {
                return 1;
            }
            if (1 < count) {
                if (tag2[0] == 'h') {
                    if (func_002E3380(buf260, text) == 0) {
                        return 1;
                    }
                }
            }
        }
    }
    if (arg0[0] == '&') {
        c = arg0[1];
        if (c == '<') {
            d = arg0[2];
            if (d == '>' && arg0[3] == 'C' && arg0[4] == 'U' && arg0[5] == 'D' &&
                arg0[6] == 'G' && arg0[7] == 'G' && arg0[8] == '<') {
                return 1;
            }
            if (d == 'U' && arg0[3] == '@' && arg0[4] == 'G') {
                return 1;
            }
        }
        if (c == '@' && arg0[2] == 'Q') {
            return 1;
        }
        if (c == 'J' && arg0[2] == 'M' && arg0[3] == 'D') {
            return 1;
        }
        if (*name == 'H' && func_002E3380(buf260, name) == 0) {
            return 1;
        }
        if (0 < count) {
            if (buf60[0] == 'H' && func_002E3380(buf260, buf60) == 0) {
                return 1;
            }
            if (1 < count) {
                if (tag2[0] == 'H') {
                    if (func_002E3380(buf260, text) == 0) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
