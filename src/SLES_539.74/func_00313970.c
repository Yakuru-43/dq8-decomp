// range: 0x313970 0x313A70
#include "common.h"

typedef struct Obj520 {
    s32 field_00;                             /* 0x00 */
    s32 field_04;                             /* 0x04 */
    s32 field_08;                             /* 0x08 */
    s32 field_0C;                             /* 0x0C */
    s32 field_10;                             /* 0x10 */
    char name[0x10];                          /* 0x14 */
    s32 field_24;                             /* 0x24 */
    s32 field_28;                             /* 0x28 */
    char field_2C[0x14];                      /* 0x2C */
    char field_40[0x20];                      /* 0x40 */
    char field_60[0x10];                      /* 0x60 */
    char field_70[0x10];                      /* 0x70 */
    char field_80[0x10];                      /* 0x80 */
    char field_90[0x10];                      /* 0x90 */
    char field_A0[0x10];                      /* 0xA0 */
    char field_B0[0x10];                      /* 0xB0 */
    char pad_C0[0x130];                       /* 0xC0 */
    s32 field_1F0;                            /* 0x1F0 */
    char pad_1F4[8];                          /* 0x1F4 */
    s32 field_1FC;                            /* 0x1FC */
} Obj520;                                     /* 0x200 */

extern void func_001340C0(void *dst, char *src);
extern void func_00313A70(Obj520 *dst, Obj520 *src);

s32 func_00313970(Obj520 *obj, char *arg1, char *arg2) {
    char buf1[0x40];
    char buf2[0x20];

    if (arg2 == 0) {
        return 0;
    }
    obj->field_00 = -1;
    obj->field_04 = 0;
    obj->field_0C = -1;
    obj->field_10 = -1;
    obj->field_1FC = -1;
    if (obj->field_1F0 <= 0) {
        obj->field_1F0 = 10;
    }
    func_001340C0(buf1, arg1);
    func_001340C0(obj->field_40, buf1);
    func_001340C0(buf2, arg2);
    obj->field_24 = 1;
    obj->field_28 = 1;
    func_001340C0(obj->field_60, buf2);
    func_001340C0(obj->field_70, buf2);
    func_001340C0(obj->field_80, buf2);
    func_001340C0(obj->field_90, buf2);
    func_001340C0(obj->field_A0, buf2);
    func_001340C0(obj->field_B0, buf2);
    func_001340C0(obj->name, buf2);
    func_00313A70(obj, obj);
    return 1;
}
