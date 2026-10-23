// range: 0x305320 0x3053C0
#include "common.h"

extern u64 func_00139848(u64, u64);
extern u64 func_00139DC8(u64, u64);

void func_00305320(u64 arg0, u64 *arg1, u64 *arg2) {
    u64 seconds;
    u64 minutes;

    seconds = func_00139848(arg0, 50);
    minutes = func_00139848(seconds, 60);
    *arg1 = func_00139848(minutes, 60);
    *arg2 = func_00139DC8(minutes, 60);
    if (seconds >= 3596401) {
        *arg1 = 999;
        *arg2 = 59;
    }
}
