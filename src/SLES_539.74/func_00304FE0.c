// range: 0x304FE0 0x305020
#include "common.h"

typedef struct {
    char pad0[0x30];
    s32 value; /* +0x30 */
    s32 limit; /* +0x34 */
} Bound;

/* Returns whether the stored limit is below the new one; stores both if apply. */
s32 func_00304FE0(Bound *bound, s32 value, s32 limit, s32 apply) {
    s32 raised;

    raised = 0;
    if (bound->limit < limit) {
        raised = 1;
    }
    if (apply != 0) {
        if (raised != 0) {
            bound->value = value;
            bound->limit = limit;
        }
    }
    return raised;
}
