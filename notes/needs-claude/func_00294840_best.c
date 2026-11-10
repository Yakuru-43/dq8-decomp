// range: 0x294840 0x294980
#include "common.h"

struct Request;
M2C_UNK func_00297BA0(s32, s32, s32, s32, s32, s32, struct Request *, u64,
                      u64);
M2C_UNK func_00359440();
extern M2C_UNK D_00421AD0 __attribute__((section(".data")));

struct Request {
    s32 id;
    s32 x10;
    s32 count;
    u8 selected;
    u8 spare;
    char payload[0x32];
};

/* ask the stream manager what is left for the unit's id, then hand the
   smaller of that and the table's own count to the reservation call */
s32 func_00294840(s32 arg0) {
    s32 obj;
    s32 e0;
    s32 sub;
    s32 id;
    s32 x10;
    s32 x12;
    s32 t;
    u64 flag;
    s32 buf[8];
    s32 n;
    s32 count;
    struct Request req;

    obj = *(s32 *)(arg0 + 0x58C);
    e0 = *(s32 *)(obj + 0xE0);
    sub = obj + 0xE0;
    id = *(s32 *)obj;
    x10 = *(s16 *)(obj + 0x10);
    x12 = *(s16 *)(obj + 0x12);
    t = *(s32 *)(obj + 0x364);
    flag = 1;
    if (t != 0) {
        if (*(u8 *)(t + 0x60) == 0) {
            flag = 0;
        }
    }
    func_00359440(&D_00421AD0, id, buf, 1, 0, 0, -1, 0);
    n = 8 - buf[x10];
    if (n < 0) {
        n = 0;
    }
    count = *(s32 *)(*(s32 *)(sub + 0x288) + 0x30);
    if (count < 0) {
        count = 0;
    }
    if (n < count) {
        count = n;
    }
    if (count <= 0) {
        return 0;
    }
    req.id = *(s32 *)(*(s32 *)(arg0 + 0x58C));
    req.x10 = *(s16 *)(*(s32 *)(arg0 + 0x58C) + 0x10);
    req.count = count;
    req.selected = 1;
    req.spare = 0;
    return 0 < func_00297BA0(arg0, e0, id, x10, x12, 1, &req, flag, flag);
}
