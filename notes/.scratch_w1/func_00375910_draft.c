// range: 0x375910 0x375A70
#include "common.h"

extern f32 func_00129E60(f32);
extern f32 D_003DF394;
extern f32 D_003DF3D0;
extern f32 D_003DF3F4;
extern s16 D_003E00A0;

typedef struct {
    f32 f_00;
    f32 f_04;
    f32 f_08;
    f32 f_0C;
    f32 f_10;
    u8 pad_14[0x24];
    s16 f_38;
    s16 f_3A;
    s8 f_3C;
} Unit;

void func_00375910(Unit *o, s16 arg1, s8 arg2) {
    f32 scale;
    f32 t;
    f32 r;
    f32 v;

    o->f_38 = arg1;
    o->f_3C = arg2;
    o->f_3A = 0;
    switch (o->f_3C) {
    case 5:
        o->f_3A = 0xF;
        break;
    case 7:
        o->f_3A = 0xF;
        o->f_10 = 0.5f;
        break;
    case 9:
    case 10:
        o->f_3A = 0xF;
        break;
    case 11:
        o->f_3A = D_003E00A0 * 5;
        scale = (f32)o->f_3A;
        t = D_003DF3D0 / (20.0f * (f32)D_003E00A0);
        r = func_00129E60(t * scale);
        v = 1.0f - D_003DF3F4 * r;
        t = D_003DF3D0 / (20.0f * (f32)D_003E00A0);
        r = func_00129E60(t * scale);
        o->f_04 = v;
        o->f_08 = 1.0f + D_003DF394 * r;
        o->f_0C = o->f_08;
        break;
    default:
        break;
    }
}
