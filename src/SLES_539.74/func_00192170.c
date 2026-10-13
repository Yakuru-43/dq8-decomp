// range: 0x192170 0x1921C0
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
s32 func_001921C0();
s32 func_001921D0();
s32 func_00192170(void)
{
  int new_var;
  s32 var_s0;
  var_s0 = func_001921D0();
  new_var = func_001921C0() > 0;
  if (new_var)
  {
    var_s0 = func_001921C0();
  }
  return var_s0;
}
