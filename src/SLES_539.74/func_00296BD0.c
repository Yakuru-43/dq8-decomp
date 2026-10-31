// range: 0x296BD0 0x296CE0
#include "common.h"

typedef struct {
    char pad0[0x8];
    s32 unk8;
    s32 unkC;
} S_state;

typedef struct {
    char pad0[0xE0];
    S_state state;
} S_58C;

typedef struct {
    char pad0[0x58C];
    S_58C *unk58C;
} S_arg0;

s32 func_00296AF0(S_arg0 *);
s32 func_00296B20(S_arg0 *);
s32 func_00296B50(S_arg0 *);
s32 func_00296B70(S_arg0 *);
s32 func_00296B90(S_arg0 *);
s32 func_00296BB0(S_arg0 *);
void func_00300CB0(void *, const char *, s32);
extern char D_003CB108[];

s32 func_00296BD0(S_arg0 *arg0) {
    S_state *state = &arg0->unk58C->state;

    if (state->unk8 == 0 || state->unkC == 0) {
        func_00296B70(arg0);
    } else if (state->unk8 == 1) {
        func_00296BB0(arg0);
    } else if (state->unk8 == 4) {
        func_00296B90(arg0);
    } else if (state->unkC == 3 || state->unkC == 5) {
        func_00296B50(arg0);
    } else if (state->unkC == 2 || state->unkC == 4) {
        func_00296B20(arg0);
    } else if (state->unkC == 1) {
        func_00296AF0(arg0);
    } else {
        func_00300CB0(0, D_003CB108, 0xAFB);
        func_00296B70(arg0);
    }
    return 1;
}
