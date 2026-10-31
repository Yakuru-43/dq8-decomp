// range: 0x463A90 0x463B20
#include "common.h"

extern s32 func_370E00(void *arg0, s32 arg1, s32 arg2);
s32 func_371490();                                  /* extern */
s32 func_3715D0(s32);                               /* extern */
s32 func_00463D30(s32);                             /* extern */
void func_00463E50(s32 arg0);                       /* extern */
void func_004643C0(s32 arg0, s32 arg1);             /* extern */

typedef struct {
    char pad0[0x18];
    s32 unk18;
    char pad1[4];
    void *unk20;
} S_arg0;

s32 func_00463A90(S_arg0 *entry) {
    s32 item;
    s32 result;

    func_370E00(entry->unk20, *(s16 *)(entry->unk18 + 0xA), 0);
    if (func_371490(entry) != 0) {
        item = func_3715D0(entry->unk18);
        result = func_00463D30(item);
        item = func_3715D0(entry->unk18);
        func_004643C0(item, 0);
        func_00463E50(result);
    }
    return 1;
}
