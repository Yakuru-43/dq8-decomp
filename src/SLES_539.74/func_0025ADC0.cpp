// range: 0x0025ADC0 0x0025AEF0
// flags: -Cpp_exceptions off
#include "common.h"
#include "stream_channel.h"

extern "C" s32 func_0025ADC0(s32 id) {
    Channel *ch = GetChannel(id);

    if (ch == NULL) {
        return -1;
    }
    return PushCommand(ch, 4);
}
