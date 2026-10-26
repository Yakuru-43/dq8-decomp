// range: 0x2D59A0 0x2D59C0
#include "common.h"

void func_002D5C20(s32, s32, s32, s32, s32, s32);    /* extern */

/* tail call: set-bit mode (1) with mask 1 over arg2 .. arg2+arg3 */
void func_002D59A0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_002D5C20(arg0, arg1, 1, 1, arg2, arg3);
}
