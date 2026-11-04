// range: 0x4609D0 0x460A70
#include "common.h"

extern M2C_UNK D_3DE8D0 __attribute__((section(".data")));

extern char *func_00460C60(char *self);
extern char *func_00460BF0(char *self);
extern char *func_00460BD0(char *self);
extern void func_00460BC0(char *p);
extern char *func_00460B90(char *p);
extern M2C_UNK **func_00460B50(M2C_UNK **arg0);
extern M2C_UNK **func_00460B10(M2C_UNK **arg0);
extern M2C_UNK **func_00460AD0(M2C_UNK **arg0);
extern M2C_UNK **func_00460A70(M2C_UNK **arg0);

char *func_004609D0(char *self) {
    char *cursor;

    func_00460C60(self);
    M2C_FIELD(self, M2C_UNK **, 0x1B0) = &D_3DE8D0;
    func_00460BF0(self + 0x4F0);
    func_00460BD0(self + 0x548);
    cursor = self + 0x558;
    do {
        func_00460BC0(cursor);
        cursor += 4;
    } while (cursor < self + 0x568);
    func_00460B90(self + 0x568);
    func_00460B50((M2C_UNK **)(self + 0x570));
    func_00460B10((M2C_UNK **)(self + 0x578));
    func_00460AD0((M2C_UNK **)(self + 0x580));
    func_00460A70((M2C_UNK **)(self + 0x588));
    return self;
}
