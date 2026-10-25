// range: 0x2148E0 0x214960
// rodata: 0x3C7D00 0x3C7D18
#include "common.h"

extern s8 D_003E08F4;
extern void func_00212850(void);
extern void func_00212F90(void);
extern void func_00213850(void);
extern void func_00214670(void);

void func_002148E0(void) {
    switch (D_003E08F4) {
    case -1:
        break;
    case 4:
        func_00214670();
        break;
    case 2:
        func_00212F90();
        break;
    case 1:
        func_00212850();
        break;
    case 0:
    case 3:
        func_00213850();
        break;
    }
}
