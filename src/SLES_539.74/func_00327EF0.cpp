// range: 0x327EF0 0x328020
#include "common.h"

extern "C" {

struct Element {
    s32 field_00;              /* precedes the vptr: vptr at +0x4 */
    virtual s32 v08(void);
    virtual s32 v0C(void);
    virtual s32 v10(void);
    virtual s32 v14(void);
    virtual f32 SetExtent(f32 lo, f32 hi);
};

f32 func_00327EF0(struct Element *elem, s32 count, s32 rows) {
    f32 half = ((f32)count - (f32)rows / 2.0f) / 2.0f;
    f32 result;

    if (half <= 0.0f) {
        result = elem->SetExtent(0.0f, 1.0f);
    } else if (half <= (f32)count / 16.0f) {
        result = elem->SetExtent(0.0f, (f32)count / 16.0f);
    } else {
        f32 base = half + elem->SetExtent(-half / 16.0f, half / 16.0f);
        result = base + elem->SetExtent(-1.0f, 1.0f);
    }
    if (result < 0.0f) {
        result = 0.0f;
    }
    return result;
}

}
