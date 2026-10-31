// range: 0x46C200 0x46C2A0
#include "common.h"

void func_0046C200(s32 *out0, s32 *out1, s32 *out2, s32 total0, s32 total1,
                  s32 total2, s32 used)
{
    s32 cur;
    s32 diff;

    cur = used;
    if (total0 <= 0) {
        *out0 = 0;
    } else {
        for (;;) {
            diff = total0 - cur;
            if (diff > 0) {
                *out0 = diff;
                break;
            }
            cur--;
            if (cur >= 0) {
                continue;
            }
            *out0 = total0;
            break;
        }
    }

    cur = used;
    if (total1 <= 0) {
        *out1 = 0;
    } else {
        for (;;) {
            diff = total1 - cur;
            if (diff > 0) {
                *out1 = diff;
                break;
            }
            cur--;
            if (cur >= 0) {
                continue;
            }
            *out1 = total1;
            break;
        }
    }

    cur = used;
    if (total2 <= 0) {
        *out2 = 0;
    } else {
        for (;;) {
            diff = total2 - cur;
            if (diff > 0) {
                *out2 = diff;
                break;
            }
            cur--;
            if (cur >= 0) {
                continue;
            }
            *out2 = total2;
            break;
        }
    }
}
