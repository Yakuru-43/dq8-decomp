// range: 0x340AE0 0x340B20
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
s32 func_0035D930(s32, M2C_UNK);
s32 func_00340AE0(s32 *arg0)
{
  s32 new_var;
  s32 temp_a0;
  ;
  if (((*arg0) != 0) & 0xFFFFu)
  {
    new_var = func_0035D930(*arg0, 1);
    return new_var & 0xFF;
  }
  return 0;
}
