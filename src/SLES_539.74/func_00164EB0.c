// range: 0x164EB0 0x165060
#include "common.h"

typedef struct {
    /* 0x00 */ s32 buttons;
    /* 0x04 */ s32 axis0;
    /* 0x08 */ s32 axis1;
    /* 0x0C */ s32 axis2;
    /* 0x10 */ s32 axis3;
} PadState;

typedef struct {
    /* 0x00 */ u8 mode;
    /* 0x01 */ u8 type;
    /* 0x02 */ u8 pos;
    /* 0x03 */ u8 neg;
    /* 0x04 */ u8 analog0;
    /* 0x05 */ u8 analog1;
    /* 0x06 */ u8 reserve[0x26];
} PadButtonInfo;

typedef struct {
    /* 0x00 */ u8 mode;
    /* 0x01 */ u8 type;
    /* 0x02 */ u8 attr;
    /* 0x03 */ u8 reserve;
} PadButtonProfile;

extern u16 D_003A1380[];

/* scePad2Read */
s32 func_0038D360(s32 port, PadButtonInfo *packet);
/* scePad2GetState */
s32 func_0038D508(s32 port);
/* scePad2GetButtonProfile */
s32 func_0038D438(s32 port, PadButtonProfile *profile);
/* scePad2GetButtonInfo */
s32 func_0038D648(s32 port, PadButtonInfo *info, s32 button);

s32 func_00164EB0(PadState *state, s32 a1, s32 a2, s32 port) {
    PadButtonInfo info;
    PadButtonProfile profile;
    s32 bits;
    s32 buttons;
    s32 profileCount;
    s32 count = 0;
    s32 mask;
    s32 i;

    if (port < 0) {
        return 0;
    }
    if (port >= 0) {
        count = func_0038D360(port, &info);
    }
    if (func_0038D508(port) != 1) {
        return 0;
    }
    if (count <= 0) {
        return 0;
    }
    profileCount = func_0038D438(port, &profile);
    if (count >= 2 && profileCount >= 2) {
        bits = profile.mode | (profile.type << 8);
        buttons = 0;
        mask = 1;
        for (i = 0; i < 16; i++) {
            if (bits & mask) {
                if (func_0038D648(port, &info, i) != 0) {
                    buttons = (buttons | D_003A1380[i]) & 0xFFFF;
                }
            }
            mask <<= 1;
        }
    }
    state->buttons = buttons & 0xFFFF;
    if (count >= 6 && profileCount >= 3 && (profile.attr & 0xF) != 0) {
        state->axis3 = info.pos;
        state->axis2 = info.neg;
        state->axis1 = info.analog0;
        state->axis0 = info.analog1;
    } else {
        state->axis3 = 0x80;
        state->axis2 = 0x80;
        state->axis1 = 0x80;
        state->axis0 = 0x80;
    }
    return count;
}
