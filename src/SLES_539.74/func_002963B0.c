// range: 0x2963B0 0x2963F0
#include "common.h"

extern s32 func_00296590(void);
extern s32 func_002963F0(void *arg);

/* the low byte of the state selects whether arg is handed on */
s32 func_002963B0(void *arg) {
    if ((func_00296590() & 0xFF) == 1) {
        return func_002963F0(arg);
    }
    return 0;
}
