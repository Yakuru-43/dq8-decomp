// range: 0x341BD0 0x341C10
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
f32 func_0035D8F0(s32);
inline int inline_fn(s32 arg0)
{
  return arg0 != 0;
}

f32 func_00341BD0(s32 *arg0)
{
  s32 temp_a0;
  short new_var;
  temp_a0 = *arg0;
  new_var = inline_fn(temp_a0);
  if (new_var)
  {
    return func_0035D8F0(temp_a0);
  }
  return 0.0f;
}
