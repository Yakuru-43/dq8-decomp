// range: 0x157E90 0x157F50
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00157E90(void *arg0, void *arg1) {
    M2C_FIELD(arg1, s32 *, 0) = 0x60000009;
    M2C_FIELD(arg1, s32 *, 4) = 0;
    M2C_FIELD(arg1, s32 *, 8) = 0;
    M2C_FIELD(arg1, s32 *, 0xC) = 0x50000009;
    M2C_FIELD(arg1, s64 *, 0x10) = (s64) M2C_FIELD(arg0, s64 *, 0x70);
    M2C_FIELD(arg1, s64 *, 0x18) = (s64) M2C_FIELD(arg0, s64 *, 0x78);
    M2C_FIELD(arg1, s64 *, 0x20) = (s64) M2C_FIELD(arg0, s64 *, 0x80);
    M2C_FIELD(arg1, s64 *, 0x28) = (s64) M2C_FIELD(arg0, s64 *, 0x88);
    M2C_FIELD(arg1, s64 *, 0x30) = (s64) M2C_FIELD(arg0, s64 *, 0x90);
    M2C_FIELD(arg1, s64 *, 0x38) = (s64) M2C_FIELD(arg0, s64 *, 0x98);
    M2C_FIELD(arg1, s64 *, 0x40) = (s64) M2C_FIELD(arg0, s64 *, 0xA0);
    M2C_FIELD(arg1, s64 *, 0x48) = (s64) M2C_FIELD(arg0, s64 *, 0xA8);
    M2C_FIELD(arg1, s64 *, 0x50) = (s64) M2C_FIELD(arg0, s64 *, 0xB0);
    M2C_FIELD(arg1, s64 *, 0x58) = (s64) M2C_FIELD(arg0, s64 *, 0xB8);
    M2C_FIELD(arg1, s64 *, 0x60) = (s64) M2C_FIELD(arg0, s64 *, 0xC0);
    M2C_FIELD(arg1, s64 *, 0x68) = (s64) M2C_FIELD(arg0, s64 *, 0xC8);
    M2C_FIELD(arg1, s64 *, 0x70) = (s64) M2C_FIELD(arg0, s64 *, 0xD0);
    M2C_FIELD(arg1, s64 *, 0x78) = (s64) M2C_FIELD(arg0, s64 *, 0xD8);
    M2C_FIELD(arg1, s64 *, 0x80) = (s64) M2C_FIELD(arg0, s64 *, 0xE0);
    M2C_FIELD(arg1, s64 *, 0x88) = (s64) M2C_FIELD(arg0, s64 *, 0xE8);
    M2C_FIELD(arg1, s64 *, 0x90) = (s64) M2C_FIELD(arg0, s64 *, 0xF0);
    M2C_FIELD(arg1, s64 *, 0x98) = (s64) M2C_FIELD(arg0, s64 *, 0xF8);
    return 0xA;
}
