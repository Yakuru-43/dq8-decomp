// best draft for func_00161590 (NOT matched) — see func_00161590.md
#include "common.h"

extern s32 func_00130F38(void *, void *, s32);
extern void func_00130FD0(void *, void *, s32);
extern void DebugPrintf(char *, char *);

typedef struct NameEntry {
    char *name;   /* 0x00 */
    s32 skip4;    /* 0x04 */
    char *text8;  /* 0x08 */
} NameEntry;

extern NameEntry D_003F8900[];
extern s32 D_003E0324;
extern u8 D_003DFBB0;
extern u8 D_003DFBB1;
extern char D_003F8100[];
extern char D_003C24C0[];
extern char D_003C24C8[];

void func_00161590(char *buf, s32 len) {
    NameEntry *e;
    char *src;
    char *p;
    char *end;
    s32 n;
    s32 count;
    s32 i;
    char seps[2];

    src = buf;
    if (src == 0 || len == 0) {
        for (i = 0; i < 0x20; i++) {
            D_003F8900[i].name = 0;
        }
        D_003E0324 = 0;
        return;
    }
    if (len >= 0x801) {
        return;
    }
    func_00130FD0(D_003F8100, src, len);
    seps[0] = D_003DFBB0;
    seps[1] = D_003DFBB1;
    p = D_003F8100;
    end = p + len;
    count = 0;
    while (p < end) {
        n = 0;
        e = &D_003F8900[count];
        e->name = p;
        e->skip4 = 0;
        while (p < end) {
            if (*p == ';') {
                e->skip4 = n;
                p++;
                e->name[n] = 0;
                n = 0;
                e->text8 = p;
            }
            if (func_00130F38(p, seps, 2) == 0) {
                p += 2;
                break;
            }
            p += 2;
            if (func_00130F38(p, seps, 1) == 0) {
                p += 1;
                break;
            }
            p += 1;
            if (func_00130F38(p, seps + 1, 1) == 0) {
                p += 1;
                break;
            }
            p += 1;
            if (*p == '\\') {
                *p = '/';
            }
            n++;
            p++;
        }
        if (e->skip4 <= 0) {
            D_003F8900[count].name = 0;
            D_003F8900[count].text8 = 0;
        } else {
            count++;
            e->text8[n] = 0;
            if (count >= 0x20) {
                break;
            }
        }
    }
    D_003E0324 = count;
    for (i = 0; i < D_003E0324; i++) {
        e = &D_003F8900[i];
        if (e->name != 0) {
            DebugPrintf(D_003C24C0, e->name);
            DebugPrintf(D_003C24C8, e->text8);
        }
    }
}
