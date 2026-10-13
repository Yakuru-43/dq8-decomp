// range: 0x3409B0 0x3409E0
// auto: m2c draft with casts added + decomp-permuter, verified byte-exact

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
s32 func_003409B0(s32 *arg0, s8 *arg1)
{
  s32 temp_v0;
  char *var_v1;
  *arg1 = 0;
  temp_v0 = *arg0;
  if (!temp_v0)
  {
    var_v1 = 0;
  }
  else
  {
    var_v1 = (char *) (temp_v0 + 0xE0);
  }
  if (var_v1 == 0)
  {
    return 0;
  }
  *arg1 = *((s8 *) (((char *) var_v1) + 0x290));
  return *((s32 *) (((char *) var_v1) + 0));
}
