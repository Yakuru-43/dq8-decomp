// range: 0x140490 0x140540
#include "common.h"

typedef struct {
    /* 0000 */ char pad_0[0x3B94];
    /* 3B94 */ char *name;
    /* 3B98 */ char *text;
    /* 3B9C */ s32 loaded;
    /* 3BA0 */ s32 *indices;
    /* 3BA4 */ char pad_3BA4[8];
    /* 3BAC */ s32 count;
} Obj;

void func_00140580(Obj *, s32);           /* extern */
void func_00140890(void);                 /* extern */
void func_001419A0(Obj *, s32, f32);      /* extern */
void func_0014E320(char *);               /* extern */
void func_0014E500(s32, char *);          /* extern */

void func_00140490(Obj *o) {
    s32 *indices;
    s32 idx;
    s32 i;

    if (o->name != 0) {
        if (o->loaded == 0) {
            func_00140890();
            i = 0;
            while (i < o->count) {
                indices = o->indices;
                if (indices != 0) {
                    idx = indices[i];
                } else {
                    idx = i;
                }
                func_001419A0(o, idx, 1.0f);
                func_00140580(o, i);
                i++;
            }
        }
        func_0014E320(o->name);
        func_0014E500((s32)o->name, o->text);
        o->name = 0;
    }
}
