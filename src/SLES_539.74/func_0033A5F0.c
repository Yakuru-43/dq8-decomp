// range: 0x33A5F0 0x33A620
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
extern f32 D_003DF5B0;
f32 func_0033A5F0(char *arg0)
{
  f32 temp_f2;
  f32 var_f0;
  temp_f2 = *((f32 *) (((char *) arg0) + 0x204));
  var_f0 = D_003DF5B0;
  if (0.0f < temp_f2)
  {
    var_f0 = temp_f2;
  }
  return var_f0;
}
