// range: 0x24B730 0x24B770
#include "common.h"

extern s32 func_0014E8A0(char *obj);
extern void func_0014DF10(char *dst, char *src, s32 size);
extern void func_002DE5B0(char *a0, char *a1);

extern char D_00416740[];
extern char D_003BD890[];

void func_0024B730(void) {
    char local[0x60];

    func_0014E8A0(local);
    func_0014DF10(local, D_00416740, 0x30);
    func_002DE5B0(local, D_003BD890);
}
