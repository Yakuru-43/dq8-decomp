// range: 0x0025D230 0x0025D390
// flags: -Cpp_exceptions off
#include "common.h"
#include "stream_channel.h"

extern "C" {
char *func_001340C0(char *dst, char *src);
u32 func_001341D8(char *s);
}

// starts streaming `name` on an idle channel
extern "C" bool func_0025D230(Channel *ch, char *name, s8 arg) {
    if (func_001341D8(name) >= 0x100) {
        return false;
    }
    {
        SemaLock lock(&ch->sema);

        if (ch->name[0] != 0) {
            return false;
        }
        func_001340C0(ch->name, name);
        ch->f14 = arg;
    }
    return PushCommand(ch, 1);
}
