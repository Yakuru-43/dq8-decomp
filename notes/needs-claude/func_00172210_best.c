// range: 0x172210 0x1723C0
#include "common.h"

extern s32 func_00130F38(void *a, void *b, s32 n);
extern u8 D_003DFC08;
extern u8 D_003DFC09;

/* Parses a command line: copies each token's characters into the write buffer
 * of the current slot (slots[slot][0]) and terminates it; a tab, or a space
 * followed by a non-space, ends the line. Returns the cursor. */
s8 *func_00172210(s32 *slots, s8 *cur, s8 *end) {
    u8 buf[2];
    s32 slot;
    s32 wofs;
    s32 *ent;
    s8 c;
    s8 *p;

    buf[0] = D_003DFC08;
    buf[1] = D_003DFC09;
    slot = 0;
    while (cur < end) {
        if (func_00130F38(cur, buf, 2) == 0) {
            cur += 2;
            goto done;
        }
        if (func_00130F38(cur, buf, 1) == 0) {
            cur += 1;
            goto done;
        }
        if (func_00130F38(cur, &buf[1], 1) == 0) {
            cur += 1;
            goto done;
        }
        wofs = 0;
        ent = slots + slot;
        while (cur < end) {
            if (func_00130F38(cur, buf, 2) == 0) {
                break;
            }
            if (func_00130F38(cur, buf, 1) == 0) {
                break;
            }
            if (func_00130F38(cur, &buf[1], 1) == 0) {
                break;
            }
            c = *cur;
            if (c == 9) {
                goto line_end;
            }
            if (c == 0x20) {
                if (cur[1] != 0x20) {
                    goto line_end;
                }
            }
            if (c != 0x20) {
                p = (s8 *)ent[0];
                if (p != 0) {
                    p[wofs] = c;
                    wofs += 1;
                }
            }
            cur += 1;
            continue;
        line_end:
            if (ent[1] == 0) {
                cur += 1;
            } else {
                *(s8 *)ent[1] = 0;
            }
            break;
        }
        p = (s8 *)ent[0];
        if (p != 0) {
            p[wofs] = 0;
        }
        slot += 1;
    }
done:
    return cur;
}
