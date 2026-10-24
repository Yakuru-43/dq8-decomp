// range: 0x105D00 0x105D30
#include "common.h"

/* Number of 4-byte elements between the write and read cursors. */
s64 func_00105D00(s32 *buf) {
    return (buf[3] - buf[2]) / 4;
}
