// range: 0x1F8810 0x1F8860
#include "common.h"

extern s32 func_0015DF90(char *, void *);
extern void func_001E9A30(char *, void *);

s32 func_001F8810(char *arg0) {
    char local[0x38];

    if (*(s32 *)(arg0 + 0xA8) == 0) {
        return 0;
    }
    func_001E9A30(arg0, local);
    return func_0015DF90(arg0 + 0xB0, local);
}
