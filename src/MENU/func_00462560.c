// range: 0x462560 0x462660
#include "common.h"

s32 func_2D34C0();                                       /* extern */
M2C_UNK func_2D38E0(s32, M2C_UNK, s32, M2C_UNK);         /* extern */
M2C_UNK func_2D4AF0(s32, M2C_UNK, M2C_UNK);              /* extern */
M2C_UNK func_2D4930(s32, M2C_UNK, M2C_UNK *);            /* extern */
M2C_UNK func_2D4A40(s32, M2C_UNK, M2C_UNK *);            /* extern */
M2C_UNK func_2D4A00(s32, M2C_UNK, M2C_UNK *);            /* extern */
s32 func_168090();                                       /* extern */

typedef struct {
    s32 data[8];
} MenuLayout;

extern s8 D_003E1A54 __attribute__((section(".sdata")));
extern M2C_UNK D_00458B90 __attribute__((section(".data")));
extern M2C_UNK D_00479018 __attribute__((section(".data")));
extern M2C_UNK D_00479D10 __attribute__((section(".data")));
extern MenuLayout D_00478780 __attribute__((section(".data")));

void func_00462560(void) {
    MenuLayout layout;
    s32 *src;
    s32 *dst;
    s32 handle;
    s32 i;

    if (D_003E1A54 != 0) {
        handle = func_2D34C0();
        func_2D38E0(handle, 0x4A7, 1, -1);
        func_2D38E0(handle, 0x4A8, 1, -1);
        func_2D4AF0(handle, 0x4A7, D_00458B90);
        func_2D4930(handle, 0x4A7, &D_00479018);
        src = D_00478780.data;
        dst = layout.data;
        i = 4;
        do {
            *dst++ = *src++;
            *dst++ = *src++;
            i--;
        } while (i > 0);
        func_2D4A40(handle, 0x4A7, &layout.data[func_168090() * 4]);
        func_2D4A00(handle, 0x4A7, &D_00479D10);
    }
}
