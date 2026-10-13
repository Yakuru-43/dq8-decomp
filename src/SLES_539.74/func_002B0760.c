// range: 0x2B0760 0x2B0790
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
inline int inline_fn(u16 *arg0, u16 arg1)
{
  return ((s32) (*arg0)) < ((s32) arg1);
}

s32 func_002B0760(u16 *arg0, u16 *arg1)
{
  u16 temp_v0;
  u16 temp_v1;
  int new_var;
  temp_v1 = *arg1;
  new_var = 1;
  temp_v0 = *arg0;
  if (((s32) temp_v0) > ((s32) ((0, temp_v1))))
  {
    return new_var;
  }
  return -inline_fn(arg0, temp_v1);
}
