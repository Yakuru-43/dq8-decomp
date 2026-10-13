// range: 0x207650 0x207680
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
s16 func_00207650(s32 arg0, s32 arg1)
{
  int new_var2;
  s16 new_var;
  if ((arg1 >= 0) && (arg1 < 5))
  {
    new_var2 = arg1 * 2;
    new_var = *((s16 *) (((char *) (new_var2 + arg0)) + 0x3A));
    return new_var;
  }
  return 0;
}
