// range: 0x24F9D0 0x24F9F0
#include "common.h"

extern "C" {

/* true while the counter at arg0 is still non-negative */
s32 func_0024F9D0(s32 *arg0) {
    bool neg = arg0[0] < 0;
    return (neg != false) ^ 1;
}

}
