// range: 0x210660 0x2106B0
#include "common.h"

void func_00130FD0(void *, s32, s32);                /* extern */
void func_00210BA0(void *, s32, void *);              /* extern */

typedef struct {
    u8 pad_00[0x66E8];
    s32 f_66E8;                                       /* 0x66E8 */
    u8 pad_66EC[0x10];
    u8 list[0x78];                                    /* 0x66FC */
    u8 f_6774[8];                                     /* 0x6774 */
} InitObj;

void func_00210660(InitObj *obj, s32 value, s32 count) {
    func_00130FD0(obj->list, value, 0x78);
    obj->f_66E8 = count;
    func_00210BA0(obj->f_6774, count, obj->list);
}
