// range: 0x381160 0x3811A0
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
inline int inline_fn(s32 arg0, s32 arg1)
{
  return arg0 + arg1;
}

s32 func_00381160(s32 arg0, s32 arg1)
{
  s8 *new_var;
  if ((arg1 >= 0) && (arg1 < 5))
  {
    new_var = (s8 *) (((char *) inline_fn(arg1, arg0)) + 0x10);
    return inline_fn(*new_var, *((s16 *) (((char *) inline_fn(arg1 * 2, arg0)) + 6)));
  }
  return 0;
}
