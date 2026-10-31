// range: 0x3242F0 0x324350
#include "common.h"

extern f32 func_00320DC0(char *);
extern s32 D_003E1200;
extern char D_00453340[];

f32 func_003242F0(void) {
    if (D_003E1200 < 0 || D_003E1200 >= 4) {
        return 0.0f;
    }
    return func_00320DC0(&D_00453340[D_003E1200 * 52]);
}
