// range: 0x341B20 0x341B50
#include "common.h"

extern "C" {

extern s32 func_0035CA30(void *record, f32 scale);

s32 func_00341B20(void **arg0, s32 arg1) {
    s32 result = 0;
    void *record = *arg0;
    if ((record != 0) != false) {
        result = func_0035CA30(record, (f32)arg1);
    } else {
        result = 0;
    }
    return result;
}

}
