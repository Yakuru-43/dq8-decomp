// range: 0x46A660 0x46A7A0
#include "common.h"

struct Entry {
    char pad[0xA];
    s16 fA;
    char pad2[6];
    s16 f12;
};

struct Menu {
    char pad[0x18];
    struct Entry *f18;
};

extern char D_00479378[] __attribute__((section(".data")));
void func_133CB8(char *, char *);
char *func_222EE0(s32);
void func_2D38E0(void *, s32, s32, s32);
void func_2D7120(void *, s32, s32, s32);
void func_0046AA70(void);
s32 func_181420(void);
s32 func_2032E0(s32, s32);
s32 func_388BC0(s32);
s32 func_1FFC10(s32);
void func_37ECA0(s32, char *);
void func_37ECF0(s32, s32, s32, s32, s32);
void func_37EB60(s32, s32, s32, s32);

/* builds the six-entry label string and shows the entry's amount line */
s32 func_0046A660(struct Menu *menu, void *owner) {
    char buf[0x200];
    s32 i;
    s32 type;

    buf[0] = 0;
    for (i = 0; i < 6; i++) {
        func_133CB8(buf, func_222EE0(i));
        func_133CB8(buf, D_00479378);
    }
    func_2D38E0(owner, 0x2733, 1, -1);
    func_0046AA70();
    type = func_181420();
    menu->f18->f12 = (s8)func_388BC0((s8)func_2032E0(type, type));
    if (type == 4) {
        menu->f18->f12 = 0;
    }
    func_37ECA0(0x2733, buf);
    func_37ECF0(0x2733, func_1FFC10(0xCA), -1, -1, 4);
    func_2D7120(owner, 0x2733, 0x50, 0x64);
    func_37EB60(0x2733, 0x18703, menu->f18->f12, 1);
    return 1;
}
