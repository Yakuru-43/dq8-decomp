// range: 0x460ED0 0x460F70
#include "common.h"

s32 func_181420();                                  /* extern */
s32 func_0045F0E0(s32);                             /* extern */
s32 func_206C20(s32, s32, s32);                     /* extern */
s32 func_24C7C0(s32, s32);                          /* extern */

s32 func_00460ED0(s32 arg0) {
    s32 count;
    s32 shop;
    s32 result;
    s32 i;

    count = 0;
    func_181420();
    shop = func_0045F0E0(arg0);
    for (i = 0; i < 0x18C; i++) {
        result = func_206C20(shop, arg0, i);
        if (result > 0) {
            if (func_24C7C0(result, 8) == 0) {
                count++;
            }
        }
    }
    return count;
}
