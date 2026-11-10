// range: 0x100A40 0x100CA0
#include "common.h"

s32 func_00100A40(char *str, char *pat, s64 *out) {
    char *q;
    char *restart;
    s32 ch;
    s32 ch2;
    s64 value;
    s64 acc;

    *out = 0;
    q = pat;
    if (pat == 0) {
        return 1;
    }
    if (*pat == 'P') {
        q++;
        if (*q == 'C') {
            q++;
        }
        if (*q == 'V') {
            q++;
        }
        if (*q == 'v') {
            if (*str == 'P') {
                return 1;
            }
            if (*str == '*') {
                return 1;
            }
        }
        q = pat;
    }
    ch = *str;
    if (ch == '!' || ch == '*') {
        if (*str++ != *q++) {
            return 0;
        }
        restart = pat + 1;
        for (;;) {
            ch = *q;
            ch2 = *str;
            if (ch2 == ch) {
                q++;
                str++;
                if (ch2 != '!') {
                    continue;
                }
                ch = *str;
                value = 0;
                if (ch != '!') {
                    do {
                        acc = (s64)ch + value * 10;
                        str++;
                        ch = *str;
                        value = acc - 0x30;
                    } while (ch != '!');
                }
                *out = value;
                return 1;
            }
            do {
                ch2 = *str++;
            } while (ch2 != '!');
            do {
                ch2 = *str++;
            } while (ch2 != '!');
            if (*str == 0) {
                return 0;
            }
            q = restart;
        }
    }
    for (;;) {
        ch2 = *str;
        if (ch2 == 'P' || ch2 == 'R') {
            if (ch2 == *q) {
                q++;
                if (*q == 'C') {
                    if (*str == 'C') {
                        str++;
                    }
                    q++;
                } else {
                    str++;
                }
                ch2 = *str;
                if (ch2 == 'C') {
                    return 0;
                }
                if (*q == 'V') {
                    if (ch2 == 'V') {
                        str++;
                    }
                    q++;
                }
                if (*str == 'V') {
                    return 0;
                }
                continue;
            }
        }
        if (ch2 != *q) {
            return 0;
        }
        do {
            if (ch2 == 0) {
                return 1;
            }
            str++;
            q++;
            ch2 = *str;
        } while (ch2 == *q);
        return 0;
    }
}
