// range: 0x46B790 0x46B7F0
#include "common.h"

extern "C" {

extern s32 D_003E1B9C;
extern s32 func_1A83A0(s32);

typedef struct {
    /* 0x00 */ s32 tag;
    /* 0x04 */ s32 f4;
} NodeB790;

s32 func_0046B790(NodeB790 *n) {
    s32 r;
    s32 flag;

    r = func_1A83A0(D_003E1B9C);
    flag = (u8)((r != 0) ^ 1);
    if (n->tag == 3) {
        *(s32 *)(n->f4 + 4) = flag;
    }
    return 1;
}

}
