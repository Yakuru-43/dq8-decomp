// range: 0x476A20 0x476AC0
#include "common.h"

extern M2C_UNK D_3DE8D0 __attribute__((section(".data")));

extern char *func_0045F4E0(char *self);
extern char *func_00476C40(char *self);
extern char *func_00476C20(char *self);
extern void func_00476C10(char *p);
extern char *func_00476BE0(char *p);
extern M2C_UNK **func_00476BA0(M2C_UNK **arg0);
extern M2C_UNK **func_00476B60(M2C_UNK **arg0);
extern M2C_UNK **func_00476B20(M2C_UNK **arg0);
extern M2C_UNK **func_00476AC0(M2C_UNK **arg0);

char *func_00476A20(char *self) {
    char *cursor;

    func_0045F4E0(self);
    M2C_FIELD(self, M2C_UNK **, 0x1B0) = &D_3DE8D0;
    func_00476C40(self + 0x4F0);
    func_00476C20(self + 0x548);
    cursor = self + 0x558;
    do {
        func_00476C10(cursor);
        cursor += 4;
    } while (cursor < self + 0x568);
    func_00476BE0(self + 0x568);
    func_00476BA0((M2C_UNK **)(self + 0x570));
    func_00476B60((M2C_UNK **)(self + 0x578));
    func_00476B20((M2C_UNK **)(self + 0x580));
    func_00476AC0((M2C_UNK **)(self + 0x588));
    return self;
}
