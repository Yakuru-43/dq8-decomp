// range: 0x22B590 0x22B5D0
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
M2C_UNK func_00132D38();
f32 func_0022B590(f32 arg0, f32 arg1)
{
  f32 new_var2;
  float new_var3;
  float new_var;
  new_var = (new_var3 = arg1 - arg0);
  func_00132D38();
  new_var2 = arg0;
  return new_var + new_var2;
}
