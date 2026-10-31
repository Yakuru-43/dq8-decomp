// range: 0x341AC0 0x341AF0
#include "common.h"

extern "C" {

extern s32 func_0035C950(void *record, f32 scale);

s32 func_00341AC0(void **arg0, s32 arg1) {
    s32 result = 0;
    void *record = *arg0;
    if ((record != 0) != false) {
        result = func_0035C950(record, (f32)arg1);
    } else {
        result = 0;
    }
    return result;
}

}
