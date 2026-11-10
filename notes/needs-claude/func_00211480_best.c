// range: 0x211480 0x211680
// best draft: CLASS structural score=1 (1 words differ, 508 vs 508 bytes)
// only diff: +0x1B4 mine slti $t0,$v0,$zero / bnez $t0 vs orig slti $at,$v0,0x0 / bnez $at
// (the 0 <= idx guard around the result assignment, see note)
#include "common.h"

union Vec4 {
    u128 q;
    f32 f[4];
};

s32 func_002116A0(void *);                                             /* extern */
u32 func_00211680(u32);                                                /* extern */
char *func_0014E560(s32, u32);                                         /* extern */
void func_0014E500(s32, char *);                                       /* extern */
char *func_001903E0(void *);                                           /* extern */
void func_00190BC0(char *, union Vec4 *);                              /* extern */
s32 func_0016DD20(void *, char *, union Vec4 *, s32);                  /* extern */
void func_0013B720(union Vec4 *, char *);                              /* extern */
f32 func_001EF970(f32);                                                /* extern */
s32 func_001E69B0(char *, s32, union Vec4 *, union Vec4 *, union Vec4 *, s32, s32); /* extern */

extern f32 D_003DF394;

s32 func_00211480(void *entity) {
    union Vec4 bounds[2];
    union Vec4 box;
    union Vec4 box2;
    union Vec4 work;
    union Vec4 hit;
    s32 mgr;
    char *list;
    char *node;
    s32 result;
    char *rec;
    s32 count;
    s32 i;
    s32 idx;

    if (entity == NULL) {
        return 0;
    }
    mgr = func_002116A0(entity);
    list = func_0014E560(mgr, func_00211680(0x6000));
    node = func_001903E0(entity);
    if (node != NULL) {
        func_00190BC0(node, &box);
    }
    box2.q = box.q;
    box2.f[1] = box2.f[1] - 60.0f;
    box.f[1] = box.f[1] + 8.0f;
    for (i = 0; i < 3; i += 2) {
        bounds[0].f[i] = box.f[i] + 20.0f;
        bounds[1].f[i] = box.f[i] - 20.0f;
    }
    bounds[0].f[1] = box.f[1] + 10.0f;
    bounds[1].f[1] = box.f[1] - 60.0f;
    bounds[0].f[3] = 1.0f;
    bounds[1].f[3] = 1.0f;
    result = -1;
    count = func_0016DD20(entity, list, bounds, 256);
    rec = list;
    for (i = 0; i < count; i++, rec += 0x60) {
        if (!(M2C_FIELD(rec, s16 *, 0x44) < 1000)) {
            func_0013B720(&work, rec + 0x30);
            if (!(func_001EF970(work.f[1]) < D_003DF394)) {
                idx = func_001E69B0(rec, 1, &box2, &box, &hit, 0, 1);
                if (0 <= idx) {
                    result = M2C_FIELD(rec + idx * 96, s16 *, 0x44);
                }
            }
        }
    }
    func_0014E500(mgr, list);
    return result;
}
