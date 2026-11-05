// range: 0x19F820 0x19F940
#include "common.h"

M2C_UNK WaitSema(s32);                            /* extern */
M2C_UNK SignalSema(s32);                          /* extern */
M2C_UNK func_001208E0(void);                      /* extern */
M2C_UNK func_00120930(s32);                       /* extern */

#define REG_XGKICK (*(volatile s32 *)0x1000F520)  // hw-register
#define REG_CTRL (*(volatile s32 *)0x1000F590)    // hw-register
#define REG_CFG1 (*(volatile s32 *)0x1000B400)    // hw-register
#define REG_ST1 (*(volatile s32 *)0x1000B410)     // hw-register
#define REG_ST2 (*(volatile s32 *)0x1000B420)     // hw-register
#define REG_ST3 (*(volatile s32 *)0x1000B430)     // hw-register
#define REG_CMD (*(volatile s32 *)0x1000B000)     // hw-register
#define REG_ST4 (*(volatile s32 *)0x1000B010)     // hw-register
#define REG_ST5 (*(volatile s32 *)0x1000B020)     // hw-register
#define REG_STAT (*(volatile s32 *)0x10002010)    // hw-register
#define REG_CFG (*(volatile s32 *)0x10002020)     // hw-register

typedef struct {
    u8 pad00[0x1C];
    /* 0x1C */ s32 m1C;
    /* 0x20 */ s32 m20;
    /* 0x24 */ s32 m24;
    /* 0x28 */ s32 m28;
    /* 0x2C */ s32 m2C;
    /* 0x30 */ s32 m30;
    /* 0x34 */ s32 m34;
    /* 0x38 */ u32 m38;
    /* 0x3C */ s32 m3C;
    /* 0x40 */ s32 sema;
    /* 0x44 */ s32 m44;
} VuUnit;

s32 func_0019F820(VuUnit *unit) {
    s32 xgkick;

    WaitSema(unit->sema);
    unit->m44 = 0;
    func_001208E0();
    REG_CTRL = REG_XGKICK | 0x10000;
    REG_CFG1 = 5;
    xgkick = REG_XGKICK;
    REG_CTRL = xgkick & ~0x10000;
    func_00120930(xgkick);
    unit->m1C = REG_ST1;
    unit->m20 = REG_ST3;
    unit->m24 = REG_ST2;
    unit->m28 = REG_CFG1;
    while (REG_STAT & 0xF0) {}
    func_001208E0();
    REG_CTRL = REG_XGKICK | 0x10000;
    REG_CMD = 0;
    xgkick = REG_XGKICK;
    REG_CTRL = xgkick & ~0x10000;
    func_00120930(xgkick);
    unit->m2C = REG_ST4;
    unit->m30 = REG_ST5;
    unit->m34 = REG_CMD;
    unit->m38 = REG_CFG;
    unit->m3C = REG_STAT;
    SignalSema(unit->sema);
    return 1;
}
