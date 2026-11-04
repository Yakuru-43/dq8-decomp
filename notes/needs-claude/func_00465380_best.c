// best attempt for func_00465380 (CLASS structural score=117, 116 words differ, 580 vs 576 bytes)
// K&R definition is the key finding: the 5th parameter (out) arrives in $t0.
// range: 0x465380 0x4655C0
#include "common.h"

s32 func_181420();                                       /* extern */
s32 func_0045F910(s32);                                  /* extern */
M2C_UNK func_206C20(s32, M2C_UNK, M2C_UNK);              /* extern */
s32 func_205050(s32, s32, M2C_UNK);                      /* extern */
s32 func_3134A0(s32, s32, s32);                          /* extern */
s32 func_312490(s32, s32);                               /* extern */

s32 func_00465380(arg0, arg1, arg2, arg3, out)
s32 arg0;
s16 *arg1;
s32 arg2;
s32 arg3;
s32 *out;
{
    s32 handle;
    s32 result;
    s32 text_id;
    s32 chk1;
    s32 chk2;
    s32 val;

    handle = func_181420();
    result = func_206C20(func_0045F910(handle), arg2, arg3);
    chk1 = 0;
    chk2 = 0;
    if (func_205050(handle, arg0, 1) > 0) {
        chk1 = 1;
    }
    if (func_205050(handle, arg2, 1) > 0) {
        chk2 = 1;
    }
    *out = 0;
    if (func_3134A0(1, arg0, arg1[0]) != 0) {
        if (arg1[1] != 0) {
            *out = 2;
            return 0x4D1;
        }
    }
    text_id = 0x4B0;
    if (func_312490(arg2, arg3) != 0) {
        *out = 6;
        return 0x4D3;
    }
    if (arg0 == 4) {
        if (arg2 == 4) {
            *out = 5;
            return 0x4BE;
        }
    }
    if (arg2 != 4) {
        if (arg0 == 4) {
            if (result > 0) {
                *out = 1;
                if (chk2 == 1) {
                    text_id = 0x4BB;
                } else {
                    text_id = 0x4BA;
                }
            } else {
                if (chk2 == 1) {
                    text_id = 0x4B9;
                } else {
                    text_id = 0x4B8;
                }
            }
        } else if (arg0 != arg2) {
            val = arg1[0];
            if ((0 < val) && (0 < result)) {
                *out = 1;
                text_id = 0x4B1;
                if (chk1 != 0) {
                    if (chk2 != 0) {
                        text_id = 0x4B2;
                    }
                }
            } else {
                if ((chk1 != 0) && (chk2 != 0)) {
                    text_id = 0x4B5;
                } else if (chk2 != 0) {
                    text_id = 0x4B4;
                } else if (chk1 != 0) {
                    text_id = 0x4B3;
                }
            }
        } else {
            text_id = 0x4BC;
            if (chk1 != 0) {
                text_id = 0x4BD;
            } else if (0 < result) {
                text_id = 0x4BF;
            }
            *out = 4;
        }
        return text_id;
    }
    if (chk1 != 0) {
        text_id = 0x4B7;
    } else {
        text_id = 0x4B6;
    }
    return text_id;
}
