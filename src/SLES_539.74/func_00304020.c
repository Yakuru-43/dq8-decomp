// range: 0x304020 0x30409C
#include "common.h"

void func_0013E090(M2C_UNK *);                                       /* extern */
void func_0013B790(M2C_UNK *, M2C_UNK *, f32);                       /* extern */
void func_0013B7D0(M2C_UNK *, M2C_UNK *, M2C_UNK *);                 /* extern */
void func_0013B7B0(M2C_UNK *, M2C_UNK *, M2C_UNK *);                 /* extern */

void func_00304020(M2C_UNK *obj, M2C_UNK *arg1, f32 scale) {
    M2C_UNK buf[4];

    func_0013E090(buf);
    func_0013B790(buf, buf, scale);
    func_0013B7D0((M2C_UNK *)((char *)obj + 0x10), arg1, buf);
    func_0013B7B0(obj, arg1, buf);
    M2C_FIELD(obj, f32 *, 0x1C) = 1.0f;
    M2C_FIELD(obj, f32 *, 0xC) = 1.0f;
}
