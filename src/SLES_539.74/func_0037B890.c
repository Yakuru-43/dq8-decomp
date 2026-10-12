// range: 0x37B890 0x37B8D0
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

M2C_UNK func_0025AC00(s16);                         /* extern */

void func_0037B890(s32 arg0, s32 arg1) {
    char *temp_v1;

    if ((arg1 >= 0) && (arg1 < 4)) {
        temp_v1= (char *) ( *(s32 *) (arg0 + (arg1 * 4)));
        if (NULL != temp_v1) {
            func_0025AC00(M2C_FIELD(temp_v1, s16 *, 2));
        }
    }
}
