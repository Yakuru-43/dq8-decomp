// range: 0x2FF210 0x2FF2A0
#include "common.h"

void *func_0014EB30(M2C_UNK, s32);                   /* extern */
void *func_002F6960(void *);                         /* extern */
extern s32 D_003E10CC;
extern s32 D_003E10D0;
extern s32 D_003E10D4;

void func_002FF210(s32 arg0) {
    void *v0;

    v0 = func_0014EB30(0x1F18, arg0);
    if (v0 != NULL) {
        v0 = func_002F6960(v0);
    }
    D_003E10CC = (s32) v0;
    v0 = func_0014EB30(0x1F18, arg0);
    if (v0 != NULL) {
        v0 = func_002F6960(v0);
    }
    D_003E10D0 = (s32) v0;
    v0 = func_0014EB30(0x1F18, arg0);
    if (v0 != NULL) {
        v0 = func_002F6960(v0);
    }
    D_003E10D4 = (s32) v0;
}
