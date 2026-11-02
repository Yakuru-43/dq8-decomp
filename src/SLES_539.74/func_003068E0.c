// range: 0x003068E0 0x00306A70
#include "common.h"

extern u8 D_003DFF90 __attribute__((section(".sdata")));
extern u8 D_003DFF91 __attribute__((section(".sdata")));

extern s32 func_00130F38(void *, void *, s32);

s32 func_003068E0(char **lines, char *cur, char *end) {
    union SepBytes {
        u8 b[2];
        u32 w;
    } sb;
    u8 *sep1;
    s32 count = 0;

    sb.b[0] = D_003DFF90;
    sb.b[1] = D_003DFF91;
    while ((u32)cur < (u32)end) {
        s32 written;
        char **slot;

        if (func_00130F38(cur, sb.b,2) == 0) {
            cur += 2;
            break;
        }
        if (func_00130F38(cur, sb.b,1) == 0) {
            cur += 1;
            break;
        }
        sep1 = (u8 *)&sb.w + 1;
        if (func_00130F38(cur, sep1, 1) == 0) {
            cur += 1;
            break;
        }
        written = 0;
        slot = lines + count;
        while ((u32)cur < (u32)end) {
            if (func_00130F38(cur, sb.b,2) == 0) {
                break;
            }
            if (func_00130F38(cur, sb.b,1) == 0) {
                break;
            }
            if (func_00130F38(cur, sep1, 1) == 0) {
                break;
            }
            if (*cur == 9) {
                cur += 1;
                if (slot[1] != 0) {
                    *slot[1] = 0;
                }
                break;
            }
            if (*cur != 0x20) {
                if (slot[0] != 0) {
                    slot[0][written] = *cur;
                    written += 1;
                }
            }
            cur += 1;
        }
        if (slot[0] != 0) {
            slot[0][written] = 0;
            count += 1;
        }
    }
    return (s32)cur;
}
