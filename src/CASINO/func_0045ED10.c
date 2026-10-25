// range: 0x45ED10 0x45EEF0
// rodata: 0x47E560 0x47E588
// flags: -flag divbyzerocheck
#include "common.h"

extern char D_0047E500[] __attribute__((section(".data")));
extern char D_0047E508[] __attribute__((section(".data")));
extern char D_0047E510[] __attribute__((section(".data")));
extern char D_0047E518[] __attribute__((section(".data")));
extern char D_0047E520[] __attribute__((section(".data")));
extern char D_0047E528[] __attribute__((section(".data")));
extern char D_0047E530[] __attribute__((section(".data")));
extern char D_0047E538[] __attribute__((section(".data")));
extern char D_0047E540[] __attribute__((section(".data")));
extern char D_0047E548[] __attribute__((section(".data")));
extern char D_0047E550[] __attribute__((section(".data")));
extern void func_1340C0(s32, char *);
extern void func_133CB8(s32, char *);

/* draws `value` as eight digits, leading zeros blank */
void func_0045ED10(s32 arg0, s32 value) {
    s32 digits[8];
    s32 i;
    s32 started;

    for (i = 0; i < 8; i++) {
        digits[7 - i] = value % 10;
        value /= 10;
    }
    started = 0;
    func_1340C0(arg0, D_0047E500);
    for (i = 0; i < 8; i++) {
        switch (digits[i]) {
        case 0:
            if (started != 0 || i == 7) {
                func_133CB8(arg0, D_0047E550);
            }
            break;
        case 1:
            func_133CB8(arg0, D_0047E508);
            started = 1;
            break;
        case 2:
            func_133CB8(arg0, D_0047E510);
            started = 1;
            break;
        case 3:
            func_133CB8(arg0, D_0047E518);
            started = 1;
            break;
        case 4:
            func_133CB8(arg0, D_0047E520);
            started = 1;
            break;
        case 5:
            func_133CB8(arg0, D_0047E528);
            started = 1;
            break;
        case 6:
            func_133CB8(arg0, D_0047E530);
            started = 1;
            break;
        case 7:
            func_133CB8(arg0, D_0047E538);
            started = 1;
            break;
        case 8:
            func_133CB8(arg0, D_0047E540);
            started = 1;
            break;
        case 9:
            func_133CB8(arg0, D_0047E548);
            started = 1;
            break;
        }
    }
}
