// best draft for func_0046C210 (2026-11-05 factory-6), try_match CLASS structural score=7
// range: 0x46C210 0x46C3F0
#include "common.h"

s32 func_2D34C0();                                        /* extern */
void func_374BB0(s32, s32);                               /* extern */
s32 func_374B70(s32);                                     /* extern */
s32 func_374B90(s32, s32);                                /* extern */
s32 func_3640B0(s32);                                     /* extern */
void func_1341D8(s32);                                    /* extern */
void func_1340C0(char *, s32);                             /* extern */
s32 func_1339E0(void *, char *, ...);                     /* extern */
char *func_1FFC30(s32);                                   /* extern */
void func_374950(s32, s32 *, s32 *);                      /* extern */
void func_2D59A0(s32, s32, s32, s32);                     /* extern */
void func_2D59C0(s32, s32, s32, s32);                     /* extern */
void func_2D5FF0(s32, s32, s32, s32, s32);                /* extern */
s32 func_2D5410(s32, s32);                                /* extern */
void func_221C20(s32);                                    /* extern */
void func_2D5440(s32, s32, char *);                       /* extern */
void func_2D38E0(s32, s32, s32, s32);                     /* extern */
void func_2D4C30(s32, s32, s32, s32, s32);                /* extern */

extern char D_00479448[] __attribute__((section(".data")));

static inline s32 HasEntry(s32 arg1, s32 i, s32 count) {
    return arg1 + i < count;
}

void func_0046C210(s32 arg0, s32 arg1) {
    s32 v4CC;
    s32 v4C8;
    char str[0x408];
    char buf80[0x40];
    s32 panel;
    char *cursor;
    s32 count;
    s32 i;
    s32 item;
    s32 work;
    s32 id;

    panel = func_2D34C0();
    if (panel == 0) {
        return;
    }
    str[0] = 0;
    cursor = str;
    func_374BB0(arg0, 1);
    count = func_374B70(1);
    if (count == 0) {
        func_1339E0(cursor, func_1FFC30(0x28));
        func_2D38E0(panel, 0x186EF, 0, -1);
    } else {
        for (i = 0; i < 9; i++) {
            func_2D59A0(panel, 0x186EF, i, 1);
            if (HasEntry(arg1, i, count)) {
                id = func_374B90(arg1 + i, 1);
                item = func_3640B0(id);
                if (id > 0) {
                    func_1341D8(item);
                    func_1340C0(buf80, item);
                    cursor += func_1339E0(cursor, D_00479448, buf80);
                    func_374950(id, &v4CC, &v4C8);
                    func_2D5FF0(panel, 0x186EF, i, v4CC, v4C8);
                    func_2D59C0(panel, 0x186EF, i, 1);
                }
            }
        }
    }
    work = func_2D5410(panel, 0x520);
    if (work != 0) {
        func_221C20(work);
    }
    func_2D5440(panel, 0x520, str);
    func_2D4C30(panel, 0x186ED, count, arg1, 9);
}
