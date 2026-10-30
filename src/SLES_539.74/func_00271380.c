// range: 0x271380 0x2713D0
#include "common.h"

void func_0014DEE0(void *);
void func_00271320(void);

typedef struct {
    u8 pad_0[0xC];
    void *field_0C;
    void *field_10;
} Struct_00271380;

void func_00271380(Struct_00271380 *arg0, void *arg1) {
    if (arg1 != NULL) {
        func_00271320();
        arg0->field_0C = arg1;
        arg0->field_10 = arg1;
        func_0014DEE0(arg0->field_0C);
        func_0014DEE0(arg0->field_10);
    }
}
