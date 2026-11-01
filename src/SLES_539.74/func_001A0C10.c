// range: 0x1A0C10 0x1A0C30
// auto: m2c draft, verified byte-exact
#include "common.h"

void RotateThreadReadyQueue(s32);
extern s32 D_003DFB8C;

void func_001A0C10(void) {
    for (;;) {
        RotateThreadReadyQueue(D_003DFB8C);
    }
}
