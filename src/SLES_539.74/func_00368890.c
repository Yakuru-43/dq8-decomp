// range: 0x368890 0x368920
#include "common.h"

typedef struct {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ s32 field_C;
} Owner;

int func_00131188(char *buf, s32 flags, s32 size);
char *func_00134750(char *, char *, s32);
void func_00133CB8(char *dst, char *src);
void func_00368920(s32, char *, s32);
extern char D_003D4CD8[];

void func_00368890(Owner *owner, char *str, s32 index) {
    char buf[0x200];

    func_00131188(buf, 0, 0x200);
    func_00134750(buf, str, 0x1FE);
    buf[0x1FE] = 0;
    func_00133CB8(buf, D_003D4CD8);
    func_00368920(owner->field_C + index * 0x1F18, buf, 1);
}
