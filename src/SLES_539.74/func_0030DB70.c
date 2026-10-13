// range: 0x30DB70 0x30DBB0
#include "common.h"

extern void func_003569D0(void *out, s32 *from, s32 *to);
extern void func_0030D180(s32 *to, void *out);

struct Obj {
    char pad[0x160];
    s32 f160;
    s32 f164;
    s32 f168;
    s32 f16C;
    s32 f170;
};

/* reads a value out of the object's 0x160/0x168 pair and writes it back at
 * 0x170 */
void func_0030DB70(struct Obj *obj) {
    s64 value;

    func_003569D0(&value, &obj->f160, &obj->f168);
    func_0030D180(&obj->f170, &value);
}
