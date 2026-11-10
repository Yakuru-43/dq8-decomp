// range: 0x461580 0x461610
// best attempt, 144/144 bytes, CLASS reorder+register score=11 (see .md)
#include "common.h"

extern "C" {

typedef struct {
    u8 pad0[0x14];
    s32 m14;
} S_Handle;

extern u32 D_003E1694;
extern S_Handle *D_003E167C;

extern void func_00462320(void);
extern void func_004718A0(void);
extern void func_00478EE0(void);
extern void func_18AA00(s32);

u32 func_00461580(void) {
    S_Handle *p;

    if ((0 < D_003E1694) != false) {
        switch (D_003E1694) {
        case 1:
            func_00478EE0();
            break;
        case 2:
            func_004718A0();
            break;
        case 3:
            func_00462320();
            break;
        }
        p = D_003E167C;
        if (p != 0) {
            func_18AA00(p->m14);
        }
    }
    return D_003E1694;
}

}
