// range: 0x25A340 0x25A6A0
// flags: -flag divbyzerocheck
// (the original guards the divides with bnez + break 0, 7: #pragma divbyzerocheck)
#include "common.h"

extern s32 func_00130F38(void *a, void *b, s32 n);
extern void func_00131188(void *, s32, s32);
extern s32 func_0013A900(f32 value);
extern void DebugPrintf(const char *fmt, ...);
extern char D_003C95C8[]; /* "RIFF" */
extern char D_003C95D0[]; /* "WAVE" */
extern char D_003C95D8[]; /* "fmt " */
extern char D_003C95E0[]; /* "data " */
extern char D_003C95E8[]; /* "pflt" */
extern char D_003C95F0[]; /* "fltr" */
extern char D_003C95F8[]; /* "ctrl" */
extern char D_003C9600[]; /* "def_vol = %f\n" */
extern char D_003C9610[]; /* "loop %d,start %d\n" */

typedef union F32Bits {
    f32 f;
    u32 u;
} F32Bits;

typedef struct WavInfo {
    s32 data_off;   /* 0x00 data bytes from the start of the file */
    s32 data_size;  /* 0x04 */
    s32 sample_rate; /* 0x08 */
    s32 bits;       /* 0x0C */
    s32 pitch;      /* 0x10 rate * 4096 / 48000, capped at 0x1000 */
    s32 channels;   /* 0x14 */
    s32 kind;       /* 0x18 */
    s32 frame_step; /* 0x1C */
    s32 gran;       /* 0x20 */
    s32 loop;       /* 0x24 */
    s32 loop_blk;   /* 0x28 */
    s32 loop_rem;   /* 0x2C */
    s32 zero30;     /* 0x30 */
    s32 loop_off;   /* 0x34 */
    u8 pad38[0x50 - 0x38];
    s32 zero50;     /* 0x50 */
    u8 pad54[0x58 - 0x54];
    s32 block_count; /* 0x58 data_size / frame_step */
    u8 pad5C[0x78 - 0x5C];
    void *buffer;   /* 0x78 where the "pflt" block is copied */
    u8 pad7C[0xAC - 0x7C];
    F32Bits def_vol; /* 0xAC */
} WavInfo;

typedef struct PfltHead {
    u8 b0, b1, b2, b3;
    s32 w1, w2, w3;
} PfltHead;

typedef struct PfltBlock {
    PfltHead head;
    struct {
        s32 lo;
        s32 hi;
    } pair[48];
} PfltBlock;

s32 func_0025A340(WavInfo *info, char *riff, s32 flag) {
    char *chunk;
    char *item;
    void *buffer;
    PfltBlock *pflt;
    s32 size;
    f32 vol;
    s32 v;

    buffer = info->buffer;
    func_00131188(info, 0, 0xB0);
    info->buffer = buffer;
    if (func_00130F38(riff, D_003C95C8, 4) != 0) {
        return 0;
    }
    if (func_00130F38(riff + 8, D_003C95D0, 4) != 0) {
        return 0;
    }
    chunk = riff + 0xC;
    info->def_vol.u = 0x3F800000;
    while (1) {
        if (func_00130F38(chunk, D_003C95D8, 4) == 0) { /* "fmt " */
            item = chunk;
            size = *(s32 *)(item + 4);
            info->sample_rate = *(s32 *)(item + 0xC);
            info->bits = 0x10;
            chunk = item + 8 + size;
            info->pitch = ((u32)(*(s32 *)(item + 0xC)) << 12) / 48000;
            if (info->pitch >= 0x1001) {
                info->pitch = 0x1000;
            }
            info->channels = *(u16 *)(item + 0xA);
            info->frame_step = *(u16 *)(item + 0x14);
            info->kind = 0;
            if (*(u16 *)(item + 8) == 0x555) {
                info->kind = 1;
                info->gran = 0x20;
            } else {
                info->gran = 1;
                info->frame_step = *(u16 *)(item + 0x14);
            }
        } else if (func_00130F38(chunk, D_003C95E0, 4) == 0) { /* "data " */
            info->data_size = *(s32 *)(chunk + 4);
            info->data_off = (chunk + 8) - riff;
            info->block_count = info->data_size / info->frame_step;
            return 1;
        } else if (func_00130F38(chunk, D_003C95E8, 4) == 0) { /* "pflt" */
            item = chunk;
            size = *(s32 *)(item + 4);
            pflt = (PfltBlock *)info->buffer;
            chunk = item + 8 + size;
            if (pflt != 0) {
                *pflt = *(PfltBlock *)item;
            }
        } else if (func_00130F38(chunk, D_003C95F0, 4) == 0) { /* "fltr" */
            chunk = chunk + 8 + *(s32 *)(chunk + 4);
        } else if (func_00130F38(chunk, D_003C95F8, 4) == 0) { /* "ctrl" */
            item = chunk;
            if (flag != 0) {
                info->loop = 1;
            } else {
                info->loop = *(u8 *)(item + 8);
            }
            info->loop_blk = *(s32 *)(item + 0xC) / info->gran;
            info->loop_rem = *(s32 *)(item + 0xC) - info->loop_blk * info->gran;
            info->loop_off = info->loop_blk * info->frame_step;
            chunk = item + 8 + *(s32 *)(item + 4);
            info->zero30 = 0;
            info->zero50 = 0;
            vol = *(f32 *)(item + 0x10);
            info->def_vol.f = vol;
            v = func_0013A900(vol);
            DebugPrintf(D_003C9600, v);
            DebugPrintf(D_003C9610, info->loop, *(s32 *)(item + 0xC));
        } else {
            chunk = chunk + 8 + *(s32 *)(chunk + 4);
        }
    }
}
