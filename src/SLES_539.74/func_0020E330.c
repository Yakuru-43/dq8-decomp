// range: 0x20E330 0x20E400
#include "common.h"

void *func_0012C6C0(s32, void *, void *);
void *func_0012D2C8(s32, s32);

s32 func_0020E330(void *arg0) {
    char *obj;
    s32 state;
    s32 type;
    s32 index;
    s32 slot;
    s32 off;

    obj = arg0;
    switch (M2C_FIELD(obj, s32 *, 0xC)) {
    case 0:
        if (func_0012C6C0(1, 0, 0) == 0) {
            break;
        }
        if (func_0012D2C8(M2C_FIELD(obj, s32 *, 0x9C0), 1) != 0) {
            break;
        }
        state = M2C_FIELD(obj, s32 *, 0xC);
        M2C_FIELD(obj, s32 *, 0xC) = state + 1;
        break;
    case 1:
        if (func_0012C6C0(1, &type, &index) == 0) {
            break;
        }
        if (type != 0x11) {
            break;
        }
        if (index < 0) {
            break;
        }
        slot = M2C_FIELD(obj, s32 *, 0x9C0);
        off = slot * 0x1C;
        off = off + (s32)obj;
        *(s32 *)(off + 0x6BC0) = 0;
        return 1;
    }
    return 0;
}
