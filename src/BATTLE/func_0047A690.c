// range: 0x47A690 0x47A740
#include "common.h"

extern s32 func_2C6BB0(char *, s32, s32);
extern s32 func_1339E0(char *, char *, ...);
extern s32 func_38A690(s32, char *);

extern char D_00484A18[]; /* "WAV\BTL\%s" */

typedef struct {
    char pad0[0x4];
    s32 unk4;
} S_owner;

typedef struct {
    s32 type;
    char pad4[0xC];
    s32 sound;
    char pad14[0x3C];
    char *name;
} S_entry;

s32 func_0047A690(s32 arg0, S_owner *arg1, S_entry *arg2) {
    char buf[0x60];
    s32 type = arg2->type;

    if (type == 1) {
        func_2C6BB0(buf, arg1->unk4, arg2->sound);
    } else if (type == 2) {
        if (arg2->sound == -1) {
            func_1339E0(buf, D_00484A18, arg2->name);
        } else {
            func_2C6BB0(buf, arg1->unk4, arg2->sound);
        }
    } else {
        func_2C6BB0(buf, arg1->unk4, arg2->sound);
    }
    func_38A690(arg1->unk4, buf);
    return 0;
}
