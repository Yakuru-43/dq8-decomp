// range: 0x220260 0x2202A0
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
s32 func_002202A0();
s32 func_00220260(s32 arg0)
{
  char *new_var2;
  s32 temp_v0;
  char *new_var;
  temp_v0 = func_002202A0();
  if (temp_v0 < 0)
  {
    return 0;
  }
  temp_v0 = temp_v0 * 2;
  new_var2 = (new_var = (char *) (temp_v0 + arg0));
  return ((0, *((s16 *) (new_var2 + 0x6A)))) != 0;
}
