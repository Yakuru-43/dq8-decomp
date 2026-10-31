// range: 0x47FC40 0x47FD00
#include "common.h"

extern "C" {

char *func_00479C50(char *);                      /* extern */
M2C_UNK func_0046E090(M2C_UNK, s32);              /* extern */
char *func_16D5B0(s32, s32);                      /* extern */
void func_151990(void *, void *);                 /* extern */
extern M2C_UNK D_003E1BD0 __attribute__((section(".sdata")));

struct S_Node {
    s32 field_0;
    f32 field_4;
    s32 addr_4() { return (s32)&field_4; }
};

s32 func_0047FC40(s32 arg0, char *arg1) {
    f32 buf[4];
    s32 temp_v0;
    s32 temp_v1;
    char *temp_a0;
    s32 temp_a1;
    char *temp_v0_2;

    temp_v0 = M2C_FIELD(arg1, s32 *, 0xB4);
    if (0 == temp_v0) {
        return 1;
    }
    temp_a0 = (char *)(temp_v0 + 8);
    if (NULL == temp_a0) {
        return 1;
    }
    temp_a1 = ((S_Node *)temp_a0)->addr_4();
    temp_v0_2 = func_00479C50(temp_a0);
    buf[0] = M2C_FIELD(temp_v0_2, f32 *, 4);
    temp_v0_2 = func_00479C50(temp_v0_2);
    buf[1] = M2C_FIELD(temp_v0_2, f32 *, 4);
    temp_v0_2 = func_00479C50(temp_v0_2);
    buf[2] = M2C_FIELD(temp_v0_2, f32 *, 4);
    temp_v0_2 = func_00479C50(temp_v0_2);
    buf[3] = 1.0f;
    temp_v1 = func_0046E090(D_003E1BD0, temp_a1);
    temp_v0_2 = func_16D5B0(arg0, temp_v1);
    if (NULL == temp_v0_2) {
        return 1;
    }
    func_151990(temp_v0_2, buf);
    return 0;
}

}
