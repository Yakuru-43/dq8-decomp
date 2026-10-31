// range: 0x140410 0x140490
#include "common.h"

extern char D_003C1F40[];
void func_0015BF80(void *);
void func_0015B830(char *, s32, char *, s32, s32, s32, s32, s32, s32, s32);

typedef struct {
    /* 00 */ u8 bit0 : 1;
    /* 01 */ u8 bit1 : 1;
    /* 02 */ u8 bit2 : 1;
    /* 03 */ u8 rest : 5;
} Flags3C04;

void func_00140410(char *arg0) {
    func_0015BF80(arg0 + 0x3BC8);
    func_0015B830(arg0 + 0x3BC8, -10, D_003C1F40, 0, 0x100, 0x100, 0x20, 0, 0, 0);
    ((Flags3C04 *)(arg0 + 0x3C04))->bit2 = 0;
}
