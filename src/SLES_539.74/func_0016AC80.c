// range: 0x16AC80 0x16AD50
#include "common.h"

char *func_0016DF20(char *, s32);       /* extern */
char *func_001EC070(char *, s32);       /* extern */
s32 func_00133F78(s32, M2C_UNK *);      /* extern */

s32 func_0016AC80(char *arg0, s32 arg1, M2C_UNK *arg2) {
    s32 i;
    s32 j;
    char *rec;
    char *list;
    char *node;

    for (i = 0; i < M2C_FIELD(arg0, s32 *, 0x3A44); i++) {
        if (i != arg1) {
            rec = func_0016DF20(arg0, i);
            if (rec != NULL) {
                list = rec + 0x70;
                if (list != NULL) {
                    for (j = 0; ; j++) {
                        node = func_001EC070(list, j);
                        if (node == NULL) {
                            break;
                        }
                        if (func_00133F78((s32)node, arg2) == 0) {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
