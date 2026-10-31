// range: 0x13F0E0 0x13F240
// flags: -flag divbyzerocheck
#include "common.h"

typedef struct GSWriter {
    char pad0[0xF4];         /* 0x00 */
    char *wp;                /* 0xF4 */
    char *f8;                /* 0xF8 */
    char *fc;                /* 0xFC */
    s32 *p100;               /* 0x100 */
    s32 *p104;               /* 0x104 */
    s32 *p108;               /* 0x108 */
    char pad10C[0x114 - 0x10C]; /* 0x10C */
    s32 mode;                /* 0x114 */
    s32 div;                 /* 0x118 */
} GSWriter;

void func_0013F0E0(GSWriter *w) {
    char *wp;
    char *end;
    s32 n1;
    s32 n2;
    s32 n3;

    if (w->mode == 0) {
        end = w->f8;
        wp = w->wp;
        n1 = (wp - end) / 16 - 1;
        n2 = (wp - w->fc) / 16 - 1;
        n3 = (wp - (char *)w->p100) / 16 - 1;
        if (n1 <= 0 || n2 <= 0) {
            w->wp = end;
        } else {
            *w->p104 = n1 | 0x10000000;
            *w->p108 = n2 | 0x50000000;
            *w->p100 = n3 | 0x8000;
        }
    } else {
        end = w->f8;
        wp = w->wp;
        n1 = (wp - end) / 16 - 1;
        n2 = (wp - w->fc) / 16 - 1;
        n3 = (wp - (char *)w->p100) / 16 - 1;
        if (n1 <= 0 || n2 <= 0) {
            w->wp = end;
            return;
        }
        *w->p104 = n1 | 0x10000000;
        *w->p108 = n2 | 0x50000000;
        *w->p100 = n3 / w->div | 0x8000;
    }
}
