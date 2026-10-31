// range: 0x140F40 0x141020
#include "common.h"

M2C_UNK func_0015F5C0();

extern void func_001095D0(u64 *, s16, s16, s16, s32, s32, s16, s16);
extern void FlushCache(s32);
extern void sceGsExecStoreImage(u64 *, void *);
extern void sceGsSyncPath(s32, s32);

struct TexHdr {
    u16 field_00;
    s16 field_02;
    s16 field_04;
    s16 field_06;
    u8 pad_08[0x30];
    u16 field_38 : 14;
    u16 pad_38 : 2;
    u16 pad_3A : 4;
    u16 field_3A : 6;
    u16 pad_3B : 6;
};

s32 func_00140F40(void *obj, struct TexHdr *hdr, void *dst) {
    u64 img[14];
    s32 n;

    func_0015F5C0();
    M2C_FIELD(obj, s32 *, 0xF1C) = 0;
    n = hdr->field_02 / 64;
    if (n == 0) {
        n = 1;
    }
    func_001095D0(img, (s16)hdr->field_38, (s16)n, (s16)hdr->field_3A, 0, 0,
                  hdr->field_02, hdr->field_04);
    FlushCache(0);
    sceGsExecStoreImage(img, dst);
    sceGsSyncPath(0, 0);
    return hdr->field_06 * (hdr->field_02 * hdr->field_04);
}
