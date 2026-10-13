// range: 0x2571D0 0x257200
// permuter-artifact: contrived C, rewrite as real C++ (see CLAUDE.md)
// auto: m2c draft + decomp-permuter, verified byte-exact

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
s32 func_002571D0(s32 *arg0, s32 *arg1)
{
  s32 new_var2;
  int new_var;
  s32 temp_v0;
  s32 temp_v1;
  temp_v1 = *arg1;
  new_var2 = *arg0;
  temp_v0 = new_var2;
  new_var = 1;
  if (temp_v0 > (*arg1))
  {
    return new_var;
  }
  if (arg0 && arg0)
  {
    arg1++;
    arg1--;
  }
  return -((0, temp_v0 < temp_v1));
}
