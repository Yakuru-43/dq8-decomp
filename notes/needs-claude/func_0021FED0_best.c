// range: 0x21FED0 0x21FFD8
#include "common.h"

void func_00222320(char *, s32);
void func_002E5800(char *, s32, s32);

s32 func_0021FED0(char *arg0) {
    s32 var_a1;
    s32 var_s0;
    char *temp_v1;
    char *temp_v1_2;
    char *temp_v1_3;
    char *temp_a0;

    M2C_FIELD(arg0, s8 *, 0) = 0;
    var_a1 = 0;
    do {
        temp_v1 = arg0 + (var_a1 * 2);
        if (M2C_FIELD(arg0, s16 *, 0x44) < M2C_FIELD(temp_v1, s16 *, 0x6A)) {
            M2C_FIELD(temp_v1, s16 *, 0x6A) = 0;
        }
        var_a1 += 1;
    } while (var_a1 < 0x10);
    var_s0 = 0;
    do {
        temp_v1 = arg0 + (var_s0 * 2);
        if (M2C_FIELD(arg0, s16 *, 0x46) < M2C_FIELD(temp_v1, s16 *, 0x4A)) {
            M2C_FIELD(temp_v1, s16 *, 0x4A) = 0;
            temp_v1_3 = arg0 + (var_s0 * 4);
            temp_a0 = M2C_FIELD(temp_v1_3, char **, 4);
            if (temp_a0 != NULL) {
                if (M2C_FIELD(arg0, s8 *, 1) != 0) {
                    func_00222320(temp_a0, 0);
                    temp_a0 = M2C_FIELD(temp_v1_3, char **, 4);
                    if (0 <= M2C_FIELD(temp_a0, s16 *, 0x1F34)) {
                        func_002E5800(temp_a0, -1, -1);
                        temp_v1_2 = M2C_FIELD(temp_v1_3, char **, 4);
                        M2C_FIELD(temp_v1_2, s16 *, 0x1624) =
                            M2C_FIELD(temp_v1_2, s16 *, 0x1F34);
                    }
                }
            }
        }
        var_s0 += 1;
    } while (var_s0 < 0x10);
    return 1;
}
