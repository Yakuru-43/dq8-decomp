// range: 0x302740 0x302850
// BEST DRAFT (did not match) — kept out of src/ per factory rule.
#include "common.h"

s32 func_002C17F0(void);
M2C_UNK *func_002A1E40(void);
s32 func_002970D0(s32, s32);

s32 func_00302740(s32 *obj, s32 flag) {
    M2C_UNK *mgr;
    u8 *tbl;
    s32 one;
    s64 prodA;
    s64 prodB;
    s32 roll;

    if (func_002C17F0() != 0) {
        return 0;
    }
    mgr = func_002A1E40();
    if (*(u8 *)((char *)mgr + 0x24) != 0 &&
            *(s32 *)((char *)mgr + 0x28) >= func_002970D0(0, 100)) {
        return *(s8 *)((char *)mgr + 0x24);
    }
    one = 1;
    tbl = (u8 *)obj[1] + (obj[7] << 6);
    tbl = (u8 *)obj[4] + ((s32)*(tbl + 1) << 1);
    prodA = (s64)one * *(u8 *)(tbl + 0x10);
    prodB = (s64)one * *(u8 *)(tbl + 0x11);
    roll = func_002970D0(one, 0x20);
    if (prodA >= roll) {
        return 1;
    }
    if (flag != 0) {
        prodB = 1;
        roll = func_002970D0((s32)prodB, 4);
    } else {
        roll = func_002970D0(1, 0x20);
    }
    if (prodB < roll) {
        return 0;
    }
    return 2;
}
