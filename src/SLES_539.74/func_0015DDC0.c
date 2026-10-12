// range: 0x15DDC0 0x15DE20
// auto: m2c draft, verified byte-exact
#include "common.h"

extern char *D_003E0298;

void func_0015DDC0(char *arg0, char *arg1) {
    char *temp_a2;

    temp_a2 = M2C_FIELD(D_003E0298, char **, 0x36B0);
    if (temp_a2 != NULL) {
        M2C_FIELD(arg0, s128 *, 0) = (s128) M2C_FIELD(temp_a2, s128 *, 0x20);
        M2C_FIELD(arg0, s128 *, 0x10) = (s128) M2C_FIELD(temp_a2, s128 *, 0x30);
        M2C_FIELD(arg0, s128 *, 0x20) = (s128) M2C_FIELD(temp_a2, s128 *, 0x40);
        M2C_FIELD(arg0, s128 *, 0x30) = (s128) M2C_FIELD(temp_a2, s128 *, 0x50);
        M2C_FIELD(arg1, s128 *, 0) = (s128) M2C_FIELD(temp_a2, s128 *, 0x60);
        M2C_FIELD(arg1, s128 *, 0x10) = (s128) M2C_FIELD(temp_a2, s128 *, 0x70);
        M2C_FIELD(arg1, s128 *, 0x20) = (s128) M2C_FIELD(temp_a2, s128 *, 0x80);
        M2C_FIELD(arg1, s128 *, 0x30) = (s128) M2C_FIELD(temp_a2, s128 *, 0x90);
    }
}
