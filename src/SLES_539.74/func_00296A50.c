// range: 0x296A50 0x296AF0
#include "common.h"

typedef struct {
    char pad0[0x10];
    s32 unk10;
    s32 unk14;
    char pad18[0x264];
    s32 unk27C;
    s32 unk280;
} S_state;

typedef struct {
    char pad0[0xE0];
    S_state state;
} S_58C;

typedef struct {
    char pad0[0x58C];
    S_58C *unk58C;
} S_arg0;

M2C_UNK func_00292960(S_arg0 *);                     /* extern */
M2C_UNK func_00291240(S_arg0 *, s32, s32);           /* extern */
M2C_UNK func_002912C0(S_arg0 *);                     /* extern */
s32 func_002915F0(S_arg0 *, u8);

s32 func_00296A50(S_arg0 *arg0) {
    S_state *state;
    s32 result;

    state = &arg0->unk58C->state;
    func_00292960(arg0);
    result = func_002915F0(arg0, 0);
    if (result > 0) {
        result = func_00291240(arg0, state->unk27C, state->unk280);
        if (result != 0) {
            state->unk10 = state->unk27C;
            state->unk14 = state->unk280;
            return 1;
        }
        func_002912C0(arg0);
        state->unk27C = state->unk10;
        state->unk280 = state->unk14;
        return 1;
    }
    return 0;
}
