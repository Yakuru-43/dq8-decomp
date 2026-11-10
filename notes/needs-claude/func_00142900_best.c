// range: 0x142900 0x142A10
#include "common.h"

void func_0014DF10(void *dst, u32 src, s32 size);   /* memcpy-like */

typedef struct Pair {
    s32 x;
    s32 y;
} Pair;

typedef struct Slot {
    Pair item[11];
} Slot;

typedef struct Rec {
    s32 field0;             /* 0x00 */
    s32 field4;             /* 0x04 */
    Slot slot;              /* 0x08 */
} Rec;

typedef struct Obj {
    char pad0[8];
    Rec *p1;                /* 0x08 -> rec1 */
    Rec *p2;                /* 0x0C -> rec2 */
    Rec rec1;               /* 0x10 */
    Rec rec2;               /* 0x70 */
} Obj;

void func_00142900(Obj *obj, Rec *src1, Rec *src2) {
    u32 addr;

    obj->rec1.field0 = src1->field0;
    obj->rec1.field4 = src1->field4;
    obj->rec1.slot = src1->slot;
    obj->rec2.field0 = src2->field0;
    obj->rec2.field4 = src2->field4;
    obj->rec2.slot = src2->slot;

    addr = src2->slot.item[5].x + (src2->slot.item[5].y << 4);
    func_0014DF10(obj->rec1.slot.item,
                  (src1->slot.item[5].x + (src1->slot.item[5].y << 4)) | 0x30000000,
                  src1->slot.item[6].y - src1->slot.item[5].y);
    func_0014DF10(obj->rec2.slot.item, addr | 0x30000000,
                  src2->slot.item[6].y - src2->slot.item[5].y);
    obj->p1 = &obj->rec1;
    obj->p2 = &obj->rec2;
}
