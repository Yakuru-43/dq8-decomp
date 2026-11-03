// range: 0x302890 0x302AC0
#include "common.h"

M2C_UNK func_0012EB08(M2C_UNK);                      /* extern */
M2C_UNK func_00130FD0(s32, M2C_UNK *, s32);          /* extern */
M2C_UNK func_0014E030(M2C_UNK);                      /* extern */
s32 func_0014E130(s32, u32);                         /* extern */
void func_0014E500(s32, M2C_UNK *);                  /* extern */
M2C_UNK *func_0014E560(s32, s32);                    /* extern */
M2C_UNK *func_00161E80(s32, M2C_UNK *, s32 *);       /* extern */
s32 func_001629F0(M2C_UNK *, M2C_UNK *, s32 *);      /* extern */
s32 func_003053C0(void);                             /* extern */
s32 func_003053E0(void);                             /* extern */
M2C_UNK DebugPrintf();                               /* extern */
extern M2C_UNK D_003D0020 __attribute__((section(".data")));
extern M2C_UNK D_003D0030 __attribute__((section(".data")));
extern M2C_UNK D_003D0050 __attribute__((section(".data")));
extern M2C_UNK D_003D0070 __attribute__((section(".data")));
extern M2C_UNK D_003D0090 __attribute__((section(".data")));

void func_00302890(s32 *obj, s32 arg1, s32 arg2, s32 arg3) {
    u8 loadDirect;
    M2C_UNK *fileName;
    M2C_UNK *buf;
    M2C_UNK *loaded;
    s32 count;
    s32 size;

    obj[0] = 0;
    obj[1] = 0;
    loadDirect = 1;
    fileName = &D_003D0020;
    buf = NULL;
    if (func_003053C0() != 0) {
        buf = &D_003D0030;
        loadDirect = 0;
    }
    if (func_003053E0() != 0) {
        loadDirect = 0;
        fileName = &D_003D0050;
        buf = &D_003D0070;
    }
    if (!loadDirect) {
        loaded = func_0014E560(arg3, 0x1900);
        if (func_001629F0(buf, loaded, &size) != 0) {
            count = func_0014E130(arg2, (size >> 4) + 1);
            func_0014E030(arg2);
            func_00130FD0(count, loaded, size);
            obj[0] = count;
            obj[1] = 0;
            if (count != 0) {
                obj[1] = obj[0] + M2C_FIELD(obj[0], s32 *, 0x34);
                obj[2] = 0;
                obj[3] = obj[0] + M2C_FIELD(obj[0], s32 *, 0x3C);
                obj[4] = obj[0] + M2C_FIELD(obj[0], s32 *, 0x44);
                obj[5] = obj[0] + M2C_FIELD(obj[0], s32 *, 0x4C);
            }
        }
        func_0014E500(arg3, loaded);
    } else {
        loaded = func_00161E80(arg1, fileName, &size);
        if (loaded != 0) {
            if (size >= 0x7800) {
                DebugPrintf(&D_003D0090);
                func_0012EB08(1);
            }
            count = func_0014E130(arg2, (size >> 4) + 1);
            func_0014E030(arg2);
            func_00130FD0(count, loaded, size);
            obj[0] = count;
            obj[1] = 0;
            if (count != 0) {
                obj[1] = obj[0] + M2C_FIELD(obj[0], s32 *, 0x34);
                obj[2] = 0;
                obj[3] = obj[0] + M2C_FIELD(obj[0], s32 *, 0x3C);
                obj[4] = obj[0] + M2C_FIELD(obj[0], s32 *, 0x44);
                obj[5] = obj[0] + M2C_FIELD(obj[0], s32 *, 0x4C);
            }
        }
    }
}
