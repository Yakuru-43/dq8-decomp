// range: 0x460F20 0x460FB0
#include "common.h"

extern void func_2F6650(char *);
extern void func_2F6640(char *, char *);
extern void func_2E4D20(char *, s32);
extern void func_2F6340(char *, s32);
extern int func_2F7540(void *, float);

void func_00460F20(char *self) {
    func_2F6650(self);
    func_2F6640(self, self + 0x1F18);
    func_2E4D20(self, 8);
    func_2F6340(self, 1);
    *(s32 *)(self + 0xE4) = 4;
    *(s8 *)(self + 0x11D4) = 1;
    *(f32 *)(self + 0x2318) = 0.0f;
    *(f32 *)(self + 0x231C) = 0.0f;
    *(f32 *)(self + 0x2320) = -1.0f;
    *(f32 *)(self + 0x2324) = -1.0f;
    *(f32 *)(self + 0x2328) = 0.0f;
    *(f32 *)(self + 0x232C) = 0.0f;
    func_2F7540(self, 1.5f);
    *(f32 *)(self + 0x2330) = 1.5f;
}
