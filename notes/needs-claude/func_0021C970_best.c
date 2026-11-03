/* Best attempt 2026-11-03 (factory-2): CLASS structural score=116, 528/536
 * bytes with -flag divbyzerocheck. The two open problems (see func_0021C970.md):
 * the `two = 1; two = two + 1;` chain gets constant-folded (mine loses
 * addiu $v1,$zero,1 / addiu $v1,$v1,1 / keeps sll instead of mult), and the
 * min-block schedules the lw early with slt into $v1 instead of $at. */
// range: 0x21C970 0x21CB90
// flags: -flag divbyzerocheck
#include "common.h"

typedef struct {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ s32 field_0C;
    /* 0x10 */ u8 pad_0C[0xF4 - 0x10];
    /* 0xF4 */ char *field_F4;
    /* 0xF8 */ s32 field_F8;
    /* 0xFC */ s32 field_FC;
    /* 0x100 */ s32 field_100;
    /* 0x104 */ char *field_104;
    /* 0x108 */ char *field_108;
    /* 0x10C */ char *field_10C;
    /* 0x110 */ char *field_110;
    /* 0x114 */ char *field_114;
    /* 0x118 */ char *field_118;
    /* 0x11C */ char *field_11C;
} SpriteBatch;

void func_0021C970(SpriteBatch *arg0, s32 arg1, s32 arg2) {
    s32 quads;
    s32 max;
    s32 n;
    s32 two;
    s32 width;
    s32 stride;
    s32 size;
    char *start;
    s32 tag0;
    s32 a;
    s32 tag1;
    s32 coordA;
    s32 b;
    s32 tagBase;
    s32 sum;
    s32 coordB;
    s32 tag2;
    s32 c;
    s32 tag3;
    s32 coordC;
    char *next;

    quads = (arg0->field_0C - 4) / 13;
    arg0->field_F8 = arg2;
    arg0->field_FC = arg1;
    arg0->field_100 = 0;
    max = quads - 1;
    if (max < arg0->field_F8) {
        arg0->field_F8 = max;
    }
    n = arg0->field_F8;
    two = 1;
    two = two + 1;
    width = n + 1;
    stride = width * 2;
    size = stride * two;
    start = arg0->field_F4;
    tag0 = 0x01000101;
    a = stride + 2;
    tag1 = 0x6C028000;
    coordA = a | 0x8000;
    b = size + 2;
    arg0->field_104 = start;
    tagBase = 0x6C000000;
    sum = size + stride;
    coordB = b | 0x8000;
    tag2 = tagBase | 0x8002;
    c = sum + 2;
    tag3 = 0x64000000;
    coordC = c | 0x8000;
    *(s32 *)(arg0->field_F4 + 4) = 0;
    *(s32 *)(arg0->field_F4 + 8) = tag0;
    *(s32 *)(arg0->field_F4 + 0xC) = tag1;
    *(s32 *)(arg0->field_F4 + 0x10) = arg0->field_FC;
    arg0->field_108 = arg0->field_F4 + 0x14;
    arg0->field_10C = arg0->field_F4 + 0x18;
    *(s32 *)(arg0->field_F4 + 0x1C) = stride;
    *(s32 *)(arg0->field_F4 + 0x20) = size;
    *(s32 *)(arg0->field_F4 + 0x24) = sum;
    *(s32 *)(arg0->field_F4 + 0x28) = 0;
    *(s32 *)(arg0->field_F4 + 0x2C) = 0;
    arg0->field_F4 += 0x30;
    *(s128 *)arg0->field_F4 = 0;
    *(s32 *)(arg0->field_F4 + 0xC) = (arg0->field_F8 << 17) | tag2;
    next = arg0->field_F4 + 0x10;
    arg0->field_F4 = next;
    arg0->field_110 = next;
    arg0->field_F4 += arg0->field_F8 << 5;
    *(s128 *)arg0->field_F4 = 0;
    *(s32 *)(arg0->field_F4 + 0xC) = (coordA | (arg0->field_F8 << 17)) | tagBase;
    next = arg0->field_F4 + 0x10;
    arg0->field_F4 = next;
    arg0->field_114 = next;
    arg0->field_F4 += arg0->field_F8 << 5;
    *(s128 *)arg0->field_F4 = 0;
    *(s32 *)(arg0->field_F4 + 0xC) = (coordB | (arg0->field_F8 << 17)) | tag3;
    next = arg0->field_F4 + 0x10;
    arg0->field_F4 = next;
    arg0->field_118 = next;
    arg0->field_F4 += arg0->field_F8 << 4;
    *(s128 *)arg0->field_F4 = 0;
    *(s32 *)(arg0->field_F4 + 0xC) = (arg0->field_F8 << 16) | coordC | tagBase;
    next = arg0->field_F4 + 0x10;
    arg0->field_F4 = next;
    arg0->field_11C = next;
    arg0->field_F4 += arg0->field_F8 << 4;
}
