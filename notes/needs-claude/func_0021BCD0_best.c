// range: 0x21BCD0 0x21BE50
// best C draft, func_0021BCD0, 2026-11-01 factory-2 (Qwen). Does NOT match
// (CLASS structural, score 93): see func_0021BCD0.md.
#include "common.h"

/* Converts a vertex stream of vec4 floats to vec3 of one of three component
 * formats: 32 = f32, 16 = u16 (scaled by 32768 / scale), 8 = u8 (scaled by
 * 128 / scale).  The quantising path runs the multiply and float->int
 * convert on the VU0. */
void func_0021BCD0(u8 *dst, f32 *src, s32 count, s32 fmt, f32 *scale) {
    s32 res[4];
    f32 scl[4];
    s32 *rp;
    f32 *sp10;
    s32 i;

    if (fmt == 32) {
        *(u128 *)scl = *(u128 *)scale;
        i = 0;
        while (i < count) {
            i = i + 1;
            ((f32 *)dst)[0] = src[0];
            ((f32 *)dst)[1] = src[1];
            ((f32 *)dst)[2] = src[2];
            src += 4;
            dst += 0xC;
        }
    } else if (fmt == 16) {
        rp = res;
        sp10 = scl;
        sp10[0] = 32768.0f / scale[0];
        sp10[1] = 32768.0f / scale[1];
        sp10[2] = 32768.0f / scale[2];
        i = 0;
        while (i < count) {
            asm {
                lqc2 vf16, 0x0(a1)
                lqc2 vf17, 0x0(t1)
                vmul.xyzw vf16, vf16, vf17
                vftoi0.xyzw vf15, vf16
                sqc2 vf15, 0x0(t2)
            }
            i = i + 1;
            src += 4;
            ((u16 *)dst)[0] = (u16)rp[0];
            ((u16 *)dst)[1] = (u16)rp[1];
            ((u16 *)dst)[2] = (u16)rp[2];
            dst += 6;
        }
    } else if (fmt == 8) {
        rp = res;
        sp10 = scl;
        sp10[0] = 128.0f / scale[0];
        sp10[1] = 128.0f / scale[1];
        sp10[2] = 128.0f / scale[2];
        i = 0;
        while (i < count) {
            asm {
                lqc2 vf16, 0x0(a1)
                lqc2 vf17, 0x0(t1)
                vmul.xyzw vf16, vf16, vf17
                vftoi0.xyzw vf15, vf16
                sqc2 vf15, 0x0(t2)
            }
            i = i + 1;
            src += 4;
            dst[0] = (u8)rp[0];
            dst[1] = (u8)rp[1];
            dst[2] = (u8)rp[2];
            dst += 3;
        }
    }
}
