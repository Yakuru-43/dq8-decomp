// range: 0x0024F4F0 0x0024F640
// flags: -Cpp_exceptions off
#include "common.h"
#include "sound_voice.h"

extern "C" bool func_0024F4F0(Voice *v) {
    {
        SemaLock lock(&v->sema);

        if (v->users > 0) {
            return false;
        }
        v->users++;
    }
    return PushVoiceCommand(v, 4);
}
