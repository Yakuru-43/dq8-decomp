// range: 0x156510 0x156610
#include "common.h"

typedef struct {
    /* 0x00 */ s32 type;
    /* 0x04 */ u8 *key;
} Entry;

typedef struct {
    /* 0x00 */ u8 pad_00[0xC];
    /* 0x0C */ s32 count;
    /* 0x10 */ Entry entries[1];
} Source;

typedef struct {
    /* 0x00 */ f32 f0;
    /* 0x04 */ f32 f4;
    /* 0x08 */ u8 pad_08[0x8];
    /* 0x10 */ u8 sub_10[0x10];
    /* 0x20 */ u8 sub_20[0x10];
} Target;

extern void (*D_003A0F10[])(void *, f32) __attribute__((section(".data")));
extern void (*D_003A0F20[])(void *, f32) __attribute__((section(".data")));

void func_00156510(Target *out, Source *in, f32 val) {
    s32 i;
    Entry *e;
    s32 count;
    u8 *key;
    void (*fp)(void *, f32);

    i = 0;
    e = in->entries;
    count = in->count;
    out->f4 = 0.0f;
    out->f0 = 0.0f;
    while (i < count) {
        key = e->key;
        switch (e->type) {
        case 5:
            out->f0 = 1.0f;
            fp = D_003A0F20[key[0]];
            if (fp != 0) {
                fp(&out->sub_10, val);
            }
            break;
        case 6:
            out->f4 = 1.0f;
            fp = D_003A0F10[key[0]];
            if (fp != 0) {
                fp(&out->sub_20, val);
            }
            break;
        }
        i++;
        e++;
    }
}
