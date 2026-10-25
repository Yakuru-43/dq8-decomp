// range: 0x30D270 0x30D390
#include "common.h"

extern s8 func_00356870(s32 *arg0);
extern s32 func_0030D1A0(s32 arg0);
extern M2C_UNK func_0030D180(s64 *, s64 *);
extern s32 func_0030D390(void *arg0);
extern s32 func_0030D3A0(s32 *arg0);
extern s32 func_0030D5A0(s32 *arg0, s64 arg1);
extern s32 func_0030D1B0(void *arg0, s32 *arg1, s32 arg2);
extern s32 func_0030CE80(s32 *arg0, s32 arg1);
extern s32 func_0030D3B0(s32 *arg0, s32 arg1);

s32 func_0030D270(s32 *obj, s64 cmd) {
    s64 result;
    s64 local30;

    M2C_FIELD(obj, s32 *, 0x15C) = func_0030D3A0((s32 *) &cmd);
    switch (func_00356870((s32 *) &cmd)) {
    case 0:
    case 1:
        return func_0030D5A0(obj, cmd);
    case 2:
        return func_0030D3B0(obj, func_0030D3A0((s32 *) &cmd));
    case 3:
        func_0030D1A0((s32) &result);
        func_0030D1B0(&local30, obj, func_0030D3A0((s32 *) &cmd));
        func_0030D180(&result, &local30);
        if (func_0030D390(&result) != 0) {
            return 0;
        }
        return func_0030D5A0(obj, result);
    case 4:
        return func_0030CE80(obj, func_0030D3A0((s32 *) &cmd));
    }
    return 0;
}
