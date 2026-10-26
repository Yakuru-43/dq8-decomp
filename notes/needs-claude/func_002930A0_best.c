// range: 0x2930A0 0x2931E0
#include "common.h"

M2C_UNK func_00359440();
M2C_UNK func_00297BA0();
extern M2C_UNK D_00421AD0 __attribute__((section(".data")));

/* the unit asks the stream manager for the counts behind its id; if any
   part is still missing, hand the request to the loader */
s32 func_002930A0(s32 arg0) {
    s32 buf[8];
    struct {
        s32 field_00;
        s32 field_04;
        s32 field_08;
        u8 field_0C;
        u8 field_0D;
        u8 pad[0x32];
    } req;
    s32 base;
    s32 arg1;
    s32 id;
    s32 index;
    s32 arg4;
    s64 ready;
    s32 count;
    s32 limit;
    s32 want;
    s32 result;
    s32 t;

    base = *(s32 *)(arg0 + 0x58C);
    arg1 = *(s32 *)(base + 0xE0);
    id = *(s32 *)(base + 0x0);
    index = *(s16 *)(base + 0x10);
    arg4 = *(s16 *)(base + 0x12);
    t = *(s32 *)(base + 0x364);
    ready = 1;
    if (t != 0) {
        if (*(u8 *)(t + 0x60) == 0) {
            ready = 0;
        }
    }
    func_00359440(&D_00421AD0, id, buf, 1, 0, 1, -1, 0);
    count = buf[index];
    limit = 8 - count;
    if (limit < 0) {
        limit = 0;
    }
    base = *(s32 *)(arg0 + 0x58C);
    want = *(s32 *)(*(s32 *)(base + 0x368) + 0x30) - count;
    if (want < 0) {
        want = 0;
    }
    if (limit < want) {
        want = limit;
    }
    if (want <= 0) {
        return 0;
    }
    req.field_00 = *(s32 *)base;
    req.field_04 = -1;
    req.field_08 = want;
    req.field_0C = 0;
    req.field_0D = 0;
    result = func_00297BA0(arg0, arg1, id, index, arg4, 1, &req,
                           (s32)ready, ready);
    return result > 0;
}
