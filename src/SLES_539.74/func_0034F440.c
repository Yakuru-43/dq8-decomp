// range: 0x34F440 0x34F540
#include "common.h"

void func_0013F6C0(void *, s32);
void func_0013EBB0(void *, s64, s64);
void func_0013F450(void *);

void func_0034F440(void *writer, s32 mode, s32 count, s32 flag) {
    if (mode == 0) {
        if (0 < count) {
            func_0013F6C0(writer, 6);
            if (flag == 0) {
                func_0013EBB0(writer, 0x40, 0x01AC001801FF0000LL);
            } else {
                func_0013EBB0(writer, 0x40, 0x01B2000401FF0000LL);
            }
            func_0013F450(writer);
        }
    }
    if (mode == 1) {
        if (0 < count) {
            func_0013F6C0(writer, 6);
            func_0013EBB0(writer, 0x40, 0x01BF000001FF0000LL);
            func_0013F450(writer);
        }
    }
}
