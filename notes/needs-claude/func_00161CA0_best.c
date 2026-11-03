// best C for func_00161CA0 (needs-claude: walk loop + delay-slot scheduling differ)
// range: 0x161CA0 0x161E00
#include "common.h"

extern s32 func_00133BE0(char *a0, char *a1);

s32 func_00161CA0(char *head, char *key, void **out, s32 count, s32 *outOff, void **outNode) {
    s32 i;
    s32 step;
    char *n;
    char *found;
    char *node;
    s32 extra;
    s32 stride;
    s32 k;
    s8 c;
    char *p;

    i = 0;
    step = 0;
    for (;;) {
        found = NULL;
        if (head != NULL) {
            n = head;
            k = 0;
            while (*n != 0) {
                if (k == step) {
                    found = n + *(s32 *)(n + 0x40);
                    extra = *(s32 *)(n + 0x44);
                    node = n;
                    break;
                }
                stride = *(s32 *)(n + 0x48);
                k++;
                n = n + stride;
            }
        }
        if (found == NULL) {
            break;
        }
        p = node;
        while (*p != 0) {
            c = *p;
            if (c == '.') {
                p++;
                break;
            }
            p++;
        }
        if (func_00133BE0(key, p) != 0) {
            step++;
            continue;
        }
        out[i] = found;
        if (outNode != NULL) {
            outNode[i] = node;
        }
        if (outOff != NULL) {
            outOff[i] = extra;
        }
        i++;
        if (i >= count) {
            break;
        }
        step++;
    }
    return i;
}
