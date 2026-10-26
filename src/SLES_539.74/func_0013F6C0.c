// range: 0x13F6C0 0x13F720
#include "common.h"

typedef struct GSWriter {
    s32 unk0;                /* 0x00 */
    char pad6C[0x70 - 0x04]; /* 0x04 */
    char pad78[0xE8 - 0x70]; /* 0x70: byte field + tail */
    s32 flag;                /* 0xE8 */
    char *base;              /* 0xEC */
    char *f0;                /* 0xF0 */
    char *wp;                /* 0xF4 */
    char *f8;                /* 0xF8 */
    char *fc;                /* 0xFC */
    s32 *p100;               /* 0x100 */
    s32 *p104;               /* 0x104 */
    s32 *p108;               /* 0x108 */
    char pad10C[0x110 - 0x10C]; /* 0x10C */
} GSWriter;

struct F300Flags {
    u8 low3 : 3;
    u8 high5 : 5;
};

void func_0013F330(GSWriter *w);                    /* extern */
void func_0013F630(GSWriter *w);                    /* extern */

void func_0013F6C0(GSWriter *w, s32 mode) {
    w->flag = 1;
    if (w->unk0 == 0) {
        return;
    }
    w->flag = 0;
    M2C_FIELD(w, struct F300Flags *, 0x70).low3 = mode;
    M2C_FIELD(w, f32 *, 0x110) = 1.0f;
    func_0013F330(w);
    func_0013F630(w);
}
