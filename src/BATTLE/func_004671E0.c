// range: 0x4671E0 0x467210
// auto: m2c draft, verified byte-exact
#include "common.h"

f32 func_13BC60();                                  /* extern */

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10, 0x14], gap at: 0x8. */
f32 func_004671E0(f32 arg0) {
    return arg0 * func_13BC60();
}
