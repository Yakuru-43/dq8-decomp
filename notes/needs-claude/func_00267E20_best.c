// best draft for func_00267E20 (NOT a match, 944 vs 932 bytes, CLASS structural
// score=237): two-phase form, correct schedule except register allocation,
// an extra saved $f24 and frame 0x20 vs 0x10.
// range: 0x00267E20 0x002681D0
#include "common.h"

f32 func_00267E20(s32 *seed) {
    f32 six = 6.0f;
    f32 sum;
    s32 v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12;

    *seed = *seed * 0x5D588B65 + 1;
    v1 = *seed;
    *seed = v1 * 0x5D588B65 + 1;
    v2 = *seed;
    *seed = v2 * 0x5D588B65 + 1;
    v3 = *seed;
    *seed = v3 * 0x5D588B65 + 1;
    v4 = *seed;
    *seed = v4 * 0x5D588B65 + 1;
    v4 = *seed;
    *seed = v4 * 0x5D588B65 + 1;
    v5 = *seed;
    *seed = v5 * 0x5D588B65 + 1;
    v6 = *seed;
    *seed = v6 * 0x5D588B65 + 1;
    v7 = *seed;
    *seed = v7 * 0x5D588B65 + 1;
    v8 = *seed;
    *seed = v8 * 0x5D588B65 + 1;
    v9 = *seed;
    *seed = v9 * 0x5D588B65 + 1;
    v10 = *seed;
    *seed = v10 * 0x5D588B65 + 1;
    v11 = *seed;
    *seed = v11 * 0x5D588B65 + 1;
    v12 = *seed;

    sum = (1.0f / 4294967296.0f) * (f32)(u32)v1 +
          (1.0f / 4294967296.0f) * (f32)(u32)v2 +
          (1.0f / 4294967296.0f) * (f32)(u32)v3 +
          (1.0f / 4294967296.0f) * (f32)(u32)v4 +
          (1.0f / 4294967296.0f) * (f32)(u32)v5 +
          (1.0f / 4294967296.0f) * (f32)(u32)v6 +
          (1.0f / 4294967296.0f) * (f32)(u32)v7 +
          (1.0f / 4294967296.0f) * (f32)(u32)v8 +
          (1.0f / 4294967296.0f) * (f32)(u32)v9 +
          (1.0f / 4294967296.0f) * (f32)(u32)v10 +
          (1.0f / 4294967296.0f) * (f32)(u32)v11 +
          (1.0f / 4294967296.0f) * (f32)(u32)v12;
    return sum - six;
}
