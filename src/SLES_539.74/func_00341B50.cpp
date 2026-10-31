// range: 0x00341B50 0x00341B80
#include "common.h"

extern "C" {

extern s32 func_0035CA40(void *record, f32 scale);

s32 func_00341B50(void **arg0, s32 arg1) {
    s32 result = 0;
    void *record = *arg0;
    if ((record != 0) != false) {
        result = func_0035CA40(record, (f32)arg1);
    } else {
        result = 0;
    }
    return result;
}

}
