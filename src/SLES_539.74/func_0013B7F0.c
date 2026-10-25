// range: 0x13B7F0 0x13B900
#include "common.h"

s32 func_0013B970();                                 /* extern */
s32 func_0013B900();                                 /* extern */

s32 func_0013B7F0(f32 *pos, f32 *mat, f32 *m0, f32 *m1) {
    f32 a[4];
    f32 b[4];

    func_0013B970(pos, mat);
    func_0013B900(a, b, m0);
    if (b[0] <= -a[0] || b[1] <= -a[1] || b[2] <= -a[2] || b[3] <= -a[3]) {
        return 0;
    }
    func_0013B900(a, b, m1);
    if (b[0] <= -a[0] || b[1] <= -a[1]) {
        return 0;
    }
    return 1;
}
