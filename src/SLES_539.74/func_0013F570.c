// range: 0x13F570 0x13F630
#include "common.h"

typedef struct GSWriter {
    s32 unk0;                /* 0x00 */
    char pad7C[0xE8 - 0x04]; /* 0x04 */
    s32 flag;                /* 0xE8 */
    char *base;              /* 0xEC */
    char *f0;                /* 0xF0 */
    char *wp;                /* 0xF4 */
    char *f8;                /* 0xF8 */
    char *fc;                /* 0xFC */
    s32 *p100;               /* 0x100 */
    s32 *p104;               /* 0x104 */
    s32 *p108;               /* 0x108 */
} GSWriter;

void func_0013F630(GSWriter *w);                        /* extern */

void func_0013F570(GSWriter *w) {
    char *end;
    char *wp;
    s32 n1;
    s32 n2;
    s32 n3;

    end = w->f8;
    wp = w->wp;
    n1 = (wp - end) / 16 - 1;
    n2 = (wp - w->fc) / 16 - 1;
    n3 = (wp - (char *) w->p100) / 16 - 1;
    if (n1 <= 0 || n2 <= 0) {
        w->wp = end;
    } else {
        *w->p104 = n1 | 0x10000000;
        *w->p108 = n2 | 0x50000000;
        *w->p100 = n3 | 0x8000;
    }
    func_0013F630(w);
}
