// range: 0x308490 0x3084D0
// permuter-artifact: contrived C, rewrite as real C++ (see CLAUDE.md)
// auto: m2c draft with casts added + decomp-permuter, verified byte-exact

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
typedef __int128 s128;
typedef unsigned __int128 u128;
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
typedef s64 M2C_UNK64;
s16 func_00308490(s32 arg0, s32 arg1, s16 arg2)
{
  s16 temp_v0;
  unsigned int new_var;
  char *temp_v1;
  if ((arg1 >= 0) && (arg1 < 0x80))
  {
    new_var = arg1 * 2;
    temp_v1 = (char *) (new_var + arg0);
    temp_v0 = ((*((s16 *) (((char *) temp_v1) + 0x150))) & 0xFFFFFFFFu) & 0xFFFFu;
    *((s16 *) (((char *) temp_v1) + 0x150)) = arg2;
    return temp_v0;
  }
  return 0;
}
