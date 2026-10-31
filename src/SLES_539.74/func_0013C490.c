// range: 0x13C490 0x13C500
#include "common.h"

extern void func_0013E0A0(f32 (*)[4], f32 *, f32 *);
extern void func_0013C500(f32 (*)[4], f32 *, f32 (*)[4], s32, f32 *, f32 *);

void func_0013C490(f32 *outMax, f32 *outMin, f32 *matrix, f32 *boxA, f32 *boxB) {
    f32 corners[8][4];

    func_0013E0A0(corners, boxA, boxB);
    func_0013C500(corners, matrix, corners, 8, outMax, outMin);
}
