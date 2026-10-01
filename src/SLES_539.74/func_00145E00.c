// range: 0x145E00 0x145F10
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00131188(char *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_00157350(char *);                      /* extern */
M2C_UNK func_00157480(char *);                      /* extern */

void func_00145E00(char *arg0) {
    s32 var_a3;
    s32 var_v1;
    char *temp_a2;
    char *temp_v0;

    M2C_FIELD(arg0, s32 *, 0x3D10) = 0;
    M2C_FIELD(arg0, s32 *, 0x3D0C) = 0;
    M2C_FIELD(arg0, s32 *, 0x3D08) = 0;
    M2C_FIELD(arg0, s32 *, 0x3D04) = 0;
    M2C_FIELD(arg0, s32 *, 0x3D00) = 0;
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 0x3B90) = 0;
    M2C_FIELD(arg0, s32 *, 0xF18) = 0;
    M2C_FIELD(arg0, s32 *, 0xF1C) = 0;
    M2C_FIELD(arg0, s32 *, 0x3B94) = 0;
    func_00131188(arg0 + 0x280, 0, 0xC80);
    M2C_FIELD(arg0, char **, 0x270) = (char *) (arg0 + 0x280);
    M2C_FIELD(arg0, char **, 0xF20) = (char *) (arg0 + 0xF30);
    func_00157350(M2C_FIELD(arg0, char **, 0xF20));
    M2C_FIELD(arg0, s32 *, 0xF00) = 0;
    M2C_FIELD(arg0, s32 *, 0xF04) = 0;
    var_v1 = 0;
    M2C_FIELD(arg0, s32 *, 0xF10) = 0x3F800000;
    M2C_FIELD(arg0, s32 *, 0xF14) = 0;
    M2C_FIELD(arg0, s32 *, 0x3C30) = 0;
    M2C_FIELD(arg0, s32 *, 0x3C34) = 0;
    do {
        temp_v0 = arg0 + (var_v1 * 4);
        var_v1 += 1;
        M2C_FIELD(temp_v0, s32 *, 0x3C38) = 0;
    } while (var_v1 < 0x20);
    M2C_FIELD(arg0, char **, 0x36B0) = (char *) (arg0 + 0x36C0);
    M2C_FIELD(arg0, char **, 0x36B4) = (char *) (arg0 + 0x3860);
    M2C_FIELD(arg0, s32 *, 0x36B8) = 0;
    M2C_FIELD(arg0, s32 *, 0x36BC) = 0;
    M2C_FIELD(arg0, s32 *, 0x3880) = 0;
    func_00157480(arg0 + 0x3890);
    M2C_FIELD(arg0, s32 *, 0x3CB8) = 0;
    var_a3 = 0;
    M2C_FIELD(arg0, s32 *, 0x3CBC) = 0;
    M2C_FIELD(arg0, s32 *, 0x3D1C) = 0;
    M2C_FIELD(arg0, s32 *, 0xF08) = 0;
    M2C_FIELD(arg0, s32 *, 0xF0C) = 0;
    do {
        temp_a2 = arg0 + (var_a3 * 0x10);
        var_a3 += 1;
        M2C_FIELD(temp_a2, s32 *, 0x3CC0) = 1;
        M2C_FIELD(temp_a2, s32 *, 0x3CCC) = -1;
    } while (var_a3 < 4);
}
