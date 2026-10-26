// range: 0x2D0520 0x2D0550
#include "common.h"

struct F4 { f32 x; f32 y; f32 z; f32 w; };
struct Src { u8 pad[0x30]; struct F4 v; };

void func_002D0520(struct F4 *arg0, struct Src *arg1)
{
    *arg0 = arg1->v;
}
