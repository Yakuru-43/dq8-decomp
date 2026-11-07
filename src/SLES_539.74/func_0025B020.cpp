// range: 0x0025B020 0x0025B150
// flags: -Cpp_exceptions off
#include "common.h"
#include "stream_channel.h"

extern "C" s32 func_0025B020(s32 id) {
    Channel *ch = GetChannel(id);

    if (ch == NULL) {
        return -1;
    }
    return PushCommand(ch, 9);
}
