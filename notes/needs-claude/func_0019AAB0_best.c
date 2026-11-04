// best attempt 2026-11-04 factory-1 (attempt 2) — compiles,
// try_match CLASS structural score=95 (94 words differ, 520 vs 516 bytes).
// The whole inner-loop diff is a 1-word cascade from ONE instruction: my
// `pkt2[1] = func_00145330(ctx) << 4;` stores as `addiu $s0,$sp,0xC4;
// sw $v0,0x0($s0)` (2 words) where the original is `sw $v0,0xC4($sp)` (1 word).
// range: 0x19AAB0 0x19ACC0
#include "common.h"

char *func_0015F490(void);
void func_0013F240(char *, s32, s32, s32, s32);
void func_0013EFF0(char *, u128 *);
void func_0013F0E0(char *);
s32 func_00145360(char *);
s32 func_00145330(char *);
s32 func_00145440(char *);
s32 func_00145450(char *);

void func_0019AAB0(char *writer) {
    char *ctx;
    s32 iy;
    s32 ix;

    ctx = func_0015F490();
    func_0013F240(writer, 6, 0x43, 0, 2);
    {
        s32 pkt2[4] = {0, 0, 0, 0};
        pkt2[0] = func_00145360(ctx) << 4;
        pkt2[1] = func_00145330(ctx) << 4;
        {
            s32 pkt1[4] = {0, 0, 0, 0};
            {
                s32 pkt0[4] = {0, 0, 0, 0};
                for (iy = 0; iy < func_00145450(ctx); iy += 0x40) {
                    for (ix = 0; ix < func_00145440(ctx); ix += 0x20) {
                        *(u128 *)pkt1 = *(u128 *)pkt2;
                        pkt0[0] = iy << 4;
                        pkt0[1] = ix << 4;
                        func_0013EFF0(writer, (u128 *)pkt0);
                        pkt1[0] = pkt0[0] + pkt2[0];
                        pkt1[1] = pkt0[1] + pkt2[1];
                        func_0013EFF0(writer, (u128 *)pkt1);
                        pkt0[0] = (iy + 0x40) << 4;
                        pkt0[1] = (ix + 0x20) << 4;
                        func_0013EFF0(writer, (u128 *)pkt0);
                        pkt1[0] = pkt0[0] + pkt2[0];
                        pkt1[1] = pkt0[1] + pkt2[1];
                        func_0013EFF0(writer, (u128 *)pkt1);
                    }
                }
            }
        }
    }
    func_0013F0E0(writer);
}
