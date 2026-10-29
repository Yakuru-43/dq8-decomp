// range: 0x1BCF90 0x1BD040
#include "common.h"

typedef struct {
    /* 0x00 */ s32 type;
    /* 0x04 */ char *ptr;
} SlotBCF90;

typedef union {
    s32 i;
    f32 f;
} ValBCF90;

typedef struct {
    /* 0x00 */ s32 tag;
    /* 0x04 */ ValBCF90 val;
} TaggedBCF90;

typedef struct {
    /* 0x00 */ SlotBCF90 slots[3];
    /* 0x18 */ TaggedBCF90 args[3];
} S_BCF90;

s32 func_001BCF90(S_BCF90 *arg0) {
    f32 a;
    f32 b;
    f32 c;
    SlotBCF90 *sl;
    TaggedBCF90 *in;
    TaggedBCF90 *in1;

    in = arg0->args;
    if (in->tag == 0) {
        a = (f32)in->val.i;
    } else {
        a = in->val.f;
    }
    in1 = in + 1;
    if (in1->tag == 0) {
        b = (f32)in1->val.i;
    } else {
        b = in1->val.f;
    }
    if (in[2].tag == 0) {
        c = (f32)in[2].val.i;
    } else {
        c = in[2].val.f;
    }
    if (arg0->slots[0].type == 3) {
        *(f32 *)(arg0->slots[0].ptr + 4) = a;
    }
    sl = arg0->slots + 1;
    if (sl->type == 3) {
        *(f32 *)(sl->ptr + 4) = b;
    }
    if (arg0->slots[2].type == 3) {
        *(f32 *)(arg0->slots[2].ptr + 4) = c;
    }
    return 1;
}
