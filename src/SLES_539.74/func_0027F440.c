// range: 0x27F440 0x27F750
#include "common.h"

typedef union Vec {
    u128 q;
    struct {
        f32 x, y, z, w;
    } v;
} Vec;

extern void func_0010ADF8(f32 *, const f32 *);

typedef struct {
    /* 0x000 */ u8 pad0[0x590];
    /* 0x590 */ Vec p590;
    /* 0x5A0 */ Vec p5A0;
    /* 0x5B0 */ Vec r5B0;
    /* 0x5C0 */ Vec p5C0;
    /* 0x5D0 */ Vec p5D0;
    /* 0x5E0 */ Vec r5E0;
    /* 0x5F0 */ Vec src5F0[4];
    /* 0x630 */ Vec tgt630[4];
    /* 0x670 */ Vec vel670[4];
    /* 0x6B0 */ Vec src6B0[4];
    /* 0x6F0 */ Vec tgt6F0[4];
    /* 0x730 */ Vec vel730[4];
    /* 0x770 */ s32 i770;
    /* 0x774 */ s32 i774;
    /* 0x778 */ s32 i778;
    /* 0x77C */ f32 f77C;
    /* 0x780 */ u8 pad1[8];
    /* 0x788 */ s32 i788;
} Sched; /* size 0x78C */

void func_0027F440(Sched *obj, s32 a1, Vec *src0, Vec *src1,
                   const f32 *vp0, const f32 *vp1, s32 mode) {
    s32 i;

    obj->src5F0[0].q = src0[0].q;
    obj->src5F0[1].q = src0[1].q;
    obj->src5F0[2].q = src0[2].q;
    obj->src5F0[3].q = src0[3].q;
    obj->src6B0[0].q = src1[0].q;
    obj->src6B0[1].q = src1[1].q;
    obj->src6B0[2].q = src1[2].q;
    obj->src6B0[3].q = src1[3].q;
    func_0010ADF8(&obj->p590.v.x, vp0);
    func_0010ADF8(&obj->p5C0.v.x, vp1);
    obj->i774 = a1;
    if (obj->tgt630[0].v.w == -1.0f) {
        obj->tgt630[0].q = src0[0].q;
        obj->tgt630[1].q = src0[1].q;
        obj->tgt630[2].q = src0[2].q;
        obj->tgt630[3].q = src0[3].q;
        obj->tgt6F0[0].q = src1[0].q;
        obj->tgt6F0[1].q = src1[1].q;
        obj->tgt6F0[2].q = src1[2].q;
        obj->tgt6F0[3].q = src1[3].q;
    }
    if (mode == 0) {
        obj->i778 = 0;
        obj->tgt630[0].q = src0[0].q;
        obj->tgt630[1].q = src0[1].q;
        obj->tgt630[2].q = src0[2].q;
        obj->tgt630[3].q = src0[3].q;
        obj->tgt6F0[0].q = src1[0].q;
        obj->tgt6F0[1].q = src1[1].q;
        obj->tgt6F0[2].q = src1[2].q;
        obj->tgt6F0[3].q = src1[3].q;
        func_0010ADF8(&obj->p5A0.v.x, vp0);
        func_0010ADF8(&obj->p5D0.v.x, vp1);
    } else if (obj->i774 != obj->i770) {
        for (i = 0; i < 4; i++) {
            obj->vel670[i].v.x = (obj->src5F0[i].v.x - obj->tgt630[i].v.x) / obj->f77C;
            obj->vel670[i].v.y = (obj->src5F0[i].v.y - obj->tgt630[i].v.y) / obj->f77C;
            obj->vel670[i].v.z = (obj->src5F0[i].v.z - obj->tgt630[i].v.z) / obj->f77C;
            obj->vel730[i].v.x = (obj->src6B0[i].v.x - obj->tgt6F0[i].v.x) / obj->f77C;
            obj->vel730[i].v.y = (obj->src6B0[i].v.y - obj->tgt6F0[i].v.y) / obj->f77C;
            obj->vel730[i].v.z = (obj->src6B0[i].v.z - obj->tgt6F0[i].v.z) / obj->f77C;
        }
        obj->r5B0.v.x = (obj->p590.v.x - obj->p5A0.v.x) / obj->f77C;
        obj->r5B0.v.y = (obj->p590.v.y - obj->p5A0.v.y) / obj->f77C;
        obj->r5B0.v.z = (obj->p590.v.z - obj->p5A0.v.z) / obj->f77C;
        obj->r5B0.v.w = 0;
        obj->r5E0.v.x = (obj->p5C0.v.x - obj->p5D0.v.x) / obj->f77C;
        obj->r5E0.v.y = (obj->p5C0.v.y - obj->p5D0.v.y) / obj->f77C;
        obj->r5E0.v.z = (obj->p5C0.v.z - obj->p5D0.v.z) / obj->f77C;
        obj->r5E0.v.w = 0;
        obj->i778 = (s32) obj->f77C;
        obj->i770 = obj->i774;
    }
    obj->i788 = 0;
}
