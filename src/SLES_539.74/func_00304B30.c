// range: 0x304B30 0x304B70
// auto: hand, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x4050];
    f32 unk4050;
} S_arg0;

extern int func_00130FD0();                          /* extern */
s32 func_00304B70(S_arg0 *);                         /* extern */

f32 func_00304B30(S_arg0 *arg0, s32 arg1) {
    func_00130FD0(arg1, &arg0->unk4050, 0x20);
    return (f32) func_00304B70(arg0);
}
