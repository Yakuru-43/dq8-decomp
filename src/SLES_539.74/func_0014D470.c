// range: 0x14D470 0x14D490
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
u8 func_0014D470(char **arg0)
{
  u8 *new_var;
  u8 new_var2;
  char *temp_v0;
  ;
  temp_v0 = *arg0;
  if (temp_v0 == 0)
  {
    return 0x20U;
  }
  new_var2 = *(new_var = (u8 *) (((char *) temp_v0) - -0x10));
  return new_var2;
}
