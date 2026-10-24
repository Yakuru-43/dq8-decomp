// range: 0x1038B0 0x1038C0
// Sets the flag at +0x36 from a2 and returns obj.
#include "common.h"

void *func_001038B0(void *obj, s32 a1, u32 a2) {
    M2C_FIELD(obj, u8 *, 0x36) = 0 < a2;
    return obj;
}
