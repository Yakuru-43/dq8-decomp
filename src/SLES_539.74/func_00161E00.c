// range: 0x161E00 0x161E80
#include "common.h"

char *func_00161ED0();

char *func_00161E00(s32 arg0, s32 arg1, s32 *arg2, char **arg3) {
    char *temp_v0;
    char *result;

    temp_v0 = func_00161ED0();
    if (temp_v0 == NULL) {
        return NULL;
    }
    if (arg2 != NULL) {
        *arg2 = *(s32 *)(temp_v0 + 0x44);
    }
    result = temp_v0 + *(s32 *)(temp_v0 + 0x40);
    if (arg3 != NULL) {
        *arg3 = NULL;
    }
    if (*(s32 *)(temp_v0 + 0x4C) == 0x270F) {
        if (arg3 != NULL) {
            *arg3 = temp_v0 + 0x50;
        }
    }
    return result;
}
