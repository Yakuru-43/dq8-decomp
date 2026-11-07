// range: 0x0024FAC0 0x0024FC80
// flags: -Cpp_exceptions off
#include "common.h"
#include "sound_voice.h"

extern "C" {
char *func_001340C0(char *dst, char *src);
u32 func_001341D8(char *s);
bool func_0024F4F0(Voice *v);
}

// loads `name` into an idle voice and starts it
extern "C" bool func_0024FAC0(Voice *v, char *name) {
    bool queued;

    {
        SemaLock lock(&v->sema);

        if (v->name == NULL) {
            return false;
        }
        if (v->name[0] != 0) {
            return false;
        }
        if (func_001341D8(name) >= 0x100) {
            return false;
        }
        func_001340C0(v->name, name);
    }
    queued = PushVoiceCommand(v, 1);
    func_0024F4F0(v);
    return queued;
}
