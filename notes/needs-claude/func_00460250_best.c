// range: 0x460250 0x460300
// Collects the eight betting categories for the casino panel: fills the
// scratch buffer, clears the shared counter, then hands each category its
// parameter block.  (Best attempt, CLASS reorder+register score=12.)
#include "common.h"

extern void func_0045FA60(void *, s32, s32, s32);
extern void func_14A9B0(void *, void *);
extern s64 D_003E16A0 __attribute__((section(".sdata")));

typedef struct {
    f32 val;
    s32 a;
    s32 b;
    s32 c;
} Param;

void func_00460250(void **ptrs, s32 count) {
    f32 buf[8];
    Param param;
    char *cursor;
    s32 i;
    u32 n;

    func_0045FA60(buf, 8, 0, 0);
    D_003E16A0 = 0;
    for (i = 0; i < count; i++) {
        void *obj = ptrs[i];
        f32 val = buf[i];
        cursor = (char *)&param;
        if (cursor != NULL) {
            n = 16;
            do {
                *cursor = 0;
                n--;
                cursor++;
            } while (n != 0);
        }
        param.val = val;
        param.a = 0;
        param.b = 0;
        func_14A9B0(obj, &param);
    }
}
