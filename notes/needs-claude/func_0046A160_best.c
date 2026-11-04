// range: 0x46A160 0x46A360
// best draft for func_0046A160 (factory-6, 2026-11-04); not committed.
// Needs D_003E1AD1 = 0x3E1AD1 in config/symbol_addrs_MENU_local.txt
// (keep_funcs.py records it once `make` links this file; the _local file
// is not editable from a factory session).
#include "common.h"

M2C_UNK func_2D38E0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_2D6970(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, f32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_2D6B20(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */
s32 func_181420();                                                      /* extern */
M2C_UNK func_205E30(s32, s32 *);                                         /* extern */
M2C_UNK func_205FB0(s32, s32 *, s32);                                    /* extern */
s32 func_201CC0();                                                      /* extern */
M2C_UNK func_22AB50(M2C_UNK);                                           /* extern */
M2C_UNK func_372E60(s32, M2C_UNK, M2C_UNK);                             /* extern */
M2C_UNK func_37CEA0(M2C_UNK);                                           /* extern */
M2C_UNK func_37CEE0(M2C_UNK);                                           /* extern */
M2C_UNK func_37D060(M2C_UNK);                                           /* extern */
M2C_UNK func_37EA60(M2C_UNK);                                           /* extern */
s32 func_3715B0(M2C_UNK);                                               /* extern */
extern s8 D_003E1ACC __attribute__((section(".sdata")));
extern s8 D_003E1AD0 __attribute__((section(".sdata")));
extern s8 D_003E1AD1 __attribute__((section(".sdata")));

typedef struct {
    char pad0[0x18];
    s32 unk18;
} S_arg0;

s32 func_0046A160(S_arg0 *arg0, s32 arg1) {
    s32 entries[4];
    s32 handle;
    s32 moved;

    func_22AB50(0);
    if (D_003E1ACC == 0) {
        D_003E1ACC = 1;
        D_003E1AD0 = func_3715B0(arg0->unk18);
        func_37D060(func_3715B0(arg0->unk18));
        func_37CEE0(0);
        func_37EA60(func_3715B0(arg0->unk18));
        func_2D38E0(arg1, 0x4A6, 1, -1);
        func_37CEA0(1);
        func_2D6B20(arg1, func_3715B0(arg0->unk18) + 0x2AF8, 0x4A6, 0, 0);
    } else if (D_003E1ACC == 1) {
        D_003E1ACC = 0;
        D_003E1AD1 = func_3715B0(arg0->unk18);
        func_37D060(-1);
        func_37EA60(-1);
        func_2D38E0(arg1, 0x4A6, 0, -1);
        func_37CEA0(0);
        if (D_003E1AD1 != D_003E1AD0) {
            handle = func_181420();
            func_205FB0(handle, entries, 0);
            moved = entries[D_003E1AD0];
            entries[D_003E1AD0] = entries[D_003E1AD1];
            func_181420();
            entries[D_003E1AD1] = moved;
            func_205E30(entries[D_003E1AD0], entries);
            func_2D6970(arg1, D_003E1AD0 + 0x2AF8, entries[D_003E1AD0] + 0x2B70,
                        0, 0.5f, 0, -1, 0);
            func_2D6970(arg1, D_003E1AD1 + 0x2AF8, entries[D_003E1AD1] + 0x2B70,
                        0, 0.5f, 0, -1, 0);
            func_372E60(func_201CC0(), 5, 1);
        }
    }
    return 1;
}
