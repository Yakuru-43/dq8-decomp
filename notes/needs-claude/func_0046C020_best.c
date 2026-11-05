// best draft for func_0046C020 (2026-11-04 factory-6), try_match CLASS structural score=71
// range: 0x46C020 0x46C210
#include "common.h"

s32 func_2D34C0();                                        /* extern */
void func_374BB0(s32, s32);                               /* extern */
char *func_374B70(s32);                                   /* extern */
s32 func_374B90(s32, s32);                                /* extern */
s32 func_3640B0(s32);                                     /* extern */
void func_1341D8(s32);                                    /* extern */
void func_1340C0(char *, s32);                             /* extern */
s32 func_1339E0(void *, char *, ...);                     /* extern */
char *func_1FFC30(s32);                                   /* extern */
void func_374740(s32, s32, s32 *, s32 *);                 /* extern */
void func_2D59A0(s32, s32, s32, s32);                     /* extern */
void func_2D59C0(s32, s32, s32, s32);                     /* extern */
void func_2D5FF0(s32, s32, s32, s32, s32);                /* extern */
s32 func_2D5410(s32, s32);                                /* extern */
void func_221C20(s32);                                    /* extern */
void func_2D5440(s32, s32, char *);                       /* extern */
void func_2D38E0(s32, s32, s32, s32);                     /* extern */
void func_2D4C30(s32, s32, s32, s32);                     /* extern */

extern char D_00479448[] __attribute__((section(".data")));

void func_0046C020(s32 arg0, s32 arg1) {
    s32 v4DC;
    s32 v4D8;
    char str[0x408];
    char buf90[0x40];
    s32 panel;
    char *cursor;
    char *count;
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
    func_374BB0(arg0, 2);
    count = func_374B70(1);
    if (count != 0) {
        for (i = 0; i < 9; i++) {
            func_2D59A0(panel, 0x186F0, i, 1);
            if (arg1 + i < (s32)count) {
                id = func_374B90(arg1 + i, 1);
                item = func_3640B0(id);
                if (id > 0) {
                    func_1341D8(item);
                    func_1340C0(buf90, item);
                    cursor += func_1339E0(cursor, D_00479448, buf90);
                    func_374740(arg0, id, &v4DC, &v4D8);
                    func_2D5FF0(panel, 0x186F0, i, v4DC, v4D8);
                    func_2D59C0(panel, 0x186F0, i, 1);
                }
            }
        }
    } else {
        func_1339E0(cursor, func_1FFC30(0x28));
        func_2D38E0(panel, 0x186F0, 0, -1);
    }
    work = func_2D5410(panel, 0x522);
    if (work != 0) {
        func_221C20(work);
    }
    func_2D5440(panel, 0x522, str);
    func_2D4C30(panel, 0x186ED, (s32)count, arg1);
}
