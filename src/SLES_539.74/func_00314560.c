// range: 0x314560 0x314590
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
s32 func_00314560(char *arg0, char *arg1)
{
  s16 temp_v0;
  s16 temp_v1;
  temp_v1 = *((s16 *) (((char *) arg1) + 2));
  temp_v0 = *((s16 *) (((char *) arg0) + 2));
  if (temp_v0 > temp_v1)
  {
    if (arg0)
    {
      return 1;
    }
    else
    {
      return 1;
    }
  }
  return -(temp_v0 < temp_v1);
}
