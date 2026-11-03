// range: 0x00161450 0x00161580
#include "common.h"

extern s32 func_001341D8(char *);
extern void func_001340C0(char *, char *);
extern void func_00133CB8(char *, char *);
extern s32 func_00134310(char *, char *, s32);
extern void DebugPrintf(char *, char *, char *);

extern s32 D_003E0324;
extern char D_003C24B0[];

typedef struct NameEntry {
    char *name;   /* 0x00 */
    s32 skip4;    /* 0x04 */
    char *text8;  /* 0x08 */
} NameEntry;
extern NameEntry D_003F8900[];

void func_00161450(char *obj, char *name) {
    char *p;
    s8 c;
    s32 len;
    s32 i;
    NameEntry *e;

    func_001340C0(obj, name);
    p = name;
    while ((c = *p) != 0) {
        if (c == ':') {
            p++;
            break;
        }
        p++;
    }
    len = func_001341D8(p);
    for (i = 0; i < D_003E0324; i++) {
        e = &D_003F8900[i];
        if (len >= e->skip4) {
            if (e->name != 0) {
                if (e->text8 != 0) {
                    if (func_00134310(e->name, p, e->skip4) == 0) {
                        func_001340C0(obj, e->text8);
                        func_00133CB8(obj, p + e->skip4);
                        DebugPrintf(D_003C24B0, name, obj);
                        break;
                    }
                }
            }
        }
    }
}
