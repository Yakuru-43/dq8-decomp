// range: 0x00341AF0 0x00341B20
#include "common.h"

extern "C" {

extern s32 func_0035C960(void *record, f32 scale);

s32 func_00341AF0(void **arg0, s32 arg1) {
    s32 result = 0;
    void *record = *arg0;
    if ((record != 0) != false) {
        result = func_0035C960(record, (f32)arg1);
    } else {
        result = 0;
    }
    return result;
}

}
