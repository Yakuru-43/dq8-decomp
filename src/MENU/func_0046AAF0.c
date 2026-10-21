// range: 0x46AAF0 0x46AC10
// auto: m2c draft, verified byte-exact
#include "common.h"

char *func_0045EEB0(M2C_UNK *);                     /* extern */
M2C_UNK func_2D38E0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 func_36D480(M2C_UNK *);                         /* extern */
M2C_UNK func_36D4B0(M2C_UNK *);                     /* extern */
M2C_UNK func_36D530(M2C_UNK *, M2C_UNK);            /* extern */
M2C_UNK func_36D670(M2C_UNK *, M2C_UNK);            /* extern */
s32 func_36E160(M2C_UNK *);                         /* extern */
s32 func_36E260(M2C_UNK *);                         /* extern */
M2C_UNK func_36E6E0(M2C_UNK *, M2C_UNK);            /* extern */
M2C_UNK func_372F70(M2C_UNK);                       /* extern */
M2C_UNK func_37AD80(M2C_UNK);                       /* extern */
M2C_UNK func_37CCA0(M2C_UNK);                       /* extern */
M2C_UNK func_37E700();                              /* extern */
extern M2C_UNK D_42D390 __attribute__((section(".data")));

s32 func_0046AAF0(s32 arg0, M2C_UNK arg1) {
    if (func_36D480(&D_42D390) != 0) {
        func_36D4B0(&D_42D390);
    } else {
        func_36D530(&D_42D390, 1);
    }
    if (func_36E160(&D_42D390) == 0) {
        if ((func_0045EEB0(&D_42D390) != NULL) && (M2C_FIELD(func_0045EEB0(&D_42D390), s32 *, 0x24) == 0)) {
            func_372F70(0);
        }
        if (func_36E260(&D_42D390) != 0) {
            func_36D670(&D_42D390, 1);
        }
    } else {
        func_36E6E0(&D_42D390, 1);
        func_37E700();
        func_37CCA0(0);
        func_2D38E0(arg1, 0x18703, 1, -1);
        func_37AD80(3);
    }
    return 1;
}
