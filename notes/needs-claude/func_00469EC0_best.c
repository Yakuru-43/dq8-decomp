// range: 0x469EC0 0x46A0C0
// best attempt 2026-11-04 factory-6: CLASS structural score=107, one-word
// shift from +0x30 (see func_00469EC0.md)
#include "common.h"

char *func_201C90(void);                                        /* extern */
s32 func_0045F120(char *);                                      /* extern */
s32 func_0046A0C0(s32);                                         /* extern */
s32 func_162CA0(void);                                          /* extern */
void func_1632D0(void *, s32, s32);                             /* extern */
void func_1632E0(void);                                         /* extern */
s32 func_181420(void);                                          /* extern */
void func_2017C0(s32, s32);                                     /* extern */
s32 func_201CC0(void);                                          /* extern */
s32 func_201E70(void);                                          /* extern */
void func_205FB0(s32, void *, s32);                             /* extern */
void func_2C0730(s32, void *);                                  /* extern */
s32 func_2C20E0(s32);                                           /* extern */
s32 func_2D34C0(void);                                          /* extern */
M2C_UNK func_2D4480(s32, s32, s32, s32);                        /* extern */
s32 func_2D6D40(s32, s32);                                      /* extern */
M2C_UNK func_2D7120(s32, s32, s32, s32);                        /* extern */
s32 func_311910(char *, s32, s32);                              /* extern */
s32 func_33E6A0(void);                                          /* extern */
M2C_UNK func_372E60(s32, s32, s32);                             /* extern */
M2C_UNK func_37CEE0(s32);                                       /* extern */
M2C_UNK func_37D060(s32);                                       /* extern */
extern s8 D_3E1AD0 __attribute__((section(".sdata")));
extern s8 D_3E1AD1 __attribute__((section(".sdata")));
extern s32 D_3E1AD4 __attribute__((section(".sdata")));

s32 func_00469EC0(s32 arg0, s32 arg1) {
    s32 buf[4];
    u8 buf2[0x80];
    s32 obj;
    s32 handle;
    s32 valA;
    s32 valB;
    s32 v201;

    func_0045F120(func_201C90());
    handle = func_2D34C0();
    obj = func_181420();
    func_205FB0(obj, buf, 0);
    valB = buf[D_3E1AD0];
    valA = buf[D_3E1AD1];
    if (arg1 != 0) {
        D_3E1AD4 = 0;
        v201 = func_201E70();
        if ((v201 != func_0046A0C0(handle)) && (func_2C20E0(handle) == 0) &&
            (func_33E6A0() == 0)) {
            D_3E1AD4 = func_311910(func_201C90(), 2, 0);
            func_2C0730(v201, buf2);
            func_1632E0();
            func_1632D0(buf2, D_3E1AD4, 0);
        }
    }
    if ((func_2D6D40(obj, valB + 0x2B70) & 0xFF) == 0) {
        if ((func_2D6D40(obj, valA + 0x2B70) & 0xFF) == 0 && func_162CA0() == 0) {
            if (D_3E1AD4 != 0) {
                func_2017C0(handle, D_3E1AD4);
            }
            valA += 0x2B70;
            func_2D4480(obj, valA, D_3E1AD1 + 0x2AF8, 1);
            valB += 0x2B70;
            func_2D4480(obj, valB, D_3E1AD0 + 0x2AF8, 1);
            func_2D7120(obj, valB, 0, 0);
            func_2D7120(obj, valA, 0, 0);
            func_37D060(D_3E1AD1);
            func_37CEE0(1);
            func_372E60(func_201CC0(), 1, 0);
        }
    }
    return 0;
}
