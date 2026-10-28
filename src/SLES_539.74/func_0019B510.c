// range: 0x19B510 0x19B560
#include "common.h"

extern void func_0015BF50(char *);

typedef struct {
    /* 00 */ u8 bit0 : 1;
    /* 01 */ u8 bit1 : 1;
    /* 02 */ u8 bit2 : 1;
    /* 03 */ u8 rest : 5;
} Flags5C;

void func_0019B510(char *arg0, s32 arg1) {
    if (arg1 == 0) {
        return;
    }
    func_0015BF50(arg0 + 0x20);
    ((Flags5C *)(arg0 + 0x5C))->bit2 = 0;
}
