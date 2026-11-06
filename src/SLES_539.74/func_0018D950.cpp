// range: 0x18D950 0x18D9E0
#include "common.h"

extern "C" {

char *func_001340C0(char *, char *);
void func_0018D9E0(s32 *, s32);
void func_0018D9F0(s32 *);

struct Object {
    s32 flags_00;                  /* 0x00 */
    u8 pad_04[4];                  /* 0x04 */
    char str_08;                   /* 0x08 */
    u8 pad_09[0x34 - 9];           /* 0x09 */
    virtual s32 v0();              /* vptr 0x34, slot 0x8 */
};

struct Derived : Object {
    void *field_38;                /* 0x38 */
};

s32 func_0018D950(Derived *obj, void *name, char *str) {
    if (name == 0) {
        return -1;
    }
    obj->v0();
    func_0018D9F0(&obj->flags_00);
    obj->field_38 = name;
    if (str == 0) {
        obj->str_08 = 0;
    } else {
        func_001340C0(&obj->str_08, str);
    }
    func_0018D9E0(&obj->flags_00, 4);
    return 0;
}

}
