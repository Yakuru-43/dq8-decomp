// range: 0x13F300 0x13F330
#include "common.h"

void func_0013F630(char *);                     /* extern */

struct F300Flags {
    u8 low3 : 3;
    u8 high5 : 5;
};

void func_0013F300(char *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x114) = 0;
    M2C_FIELD(arg0, struct F300Flags *, 0x70).low3 = arg1;
    M2C_FIELD(arg0, f32 *, 0x110) = 1.0f;
    func_0013F630(arg0);
}
