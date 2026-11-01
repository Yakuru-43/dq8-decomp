// range: 0x00165150 0x00165200
#include "common.h"

typedef struct Unit {
    char pad0[0x4];             /* 0x00 */
    s32 f_04;                   /* 0x04 */
    s32 f_08;                   /* 0x08 */
    s32 f_0C;                   /* 0x0C */
    s32 f_10;                   /* 0x10 */
    s32 f_14;                   /* 0x14 */
    s32 f_18;                   /* 0x18 */
    char pad1C[0x2C - 0x1C];    /* 0x1C */
    u8 b_2C[6];                 /* 0x2C */
    char pad32[0x38 - 0x32];    /* 0x32 */
    u8 b_38[6];                 /* 0x38 */
    char pad3E[0x44 - 0x3E];    /* 0x3E */
    s32 w_44[6];                /* 0x44 */
    char pad5C[0xC4 - 0x5C];    /* 0x5C */
    s32 f_C4;                   /* 0xC4 */
    s32 f_C8;                   /* 0xC8 */
    s32 f_CC;                   /* 0xCC */
    s32 f_D0;                   /* 0xD0 */
    s32 f_D4;                   /* 0xD4 */
    s32 a_D8[32];               /* 0xD8 */
    s32 a_158[32];              /* 0x158 */
    s32 a_1D8[32];              /* 0x1D8 */
    s32 f_258;                  /* 0x258 */
    s32 f_25C;                  /* 0x25C */
    char pad260[0x264 - 0x260]; /* 0x260 */
    s32 f_264;                  /* 0x264 */
    s32 f_268;                  /* 0x268 */
    s32 f_26C;                  /* 0x26C */
    s32 f_270;                  /* 0x270 */
} Unit;                          /* 0x274 */

void func_00165150(Unit *unit) {
    s32 i;

    unit->f_25C = 0;
    unit->f_264 = 1;
    unit->f_268 = 0;
    unit->f_26C = 0;
    unit->f_270 = 0;
    unit->f_C4 = -1;
    unit->f_C8 = -1;
    unit->f_CC = -1;
    unit->f_18 = 0;
    unit->f_04 = 0;
    unit->f_10 = 0x80;
    unit->f_14 = 0x80;
    unit->f_08 = 0x80;
    unit->f_0C = 0x80;
    i = 0;
    do {
        unit->b_2C[i] = 0;
        unit->w_44[i] = 0;
        unit->b_38[i] = 0xFF;
    } while (++i < 6);
    unit->f_258 = 0;
    unit->f_D0 = 0;
    unit->f_D4 = 0;
    i = 0;
    do {
        unit->a_D8[i] = 0;
        unit->a_1D8[i] = 0;
        unit->a_158[i] = 0;
    } while (++i < 32);
}
