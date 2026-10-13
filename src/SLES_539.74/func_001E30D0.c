// range: 0x1E30D0 0x1E30F0
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
s32 func_001E30D0(char *arg0, char *arg1)
{
  u32 temp_a0;
  u32 temp_v1;
  temp_a0 = *((u32 *) (((char *) arg0) + 8));
  temp_v1 = *((u32 *) (((char *) arg1) + 8));
  if (temp_a0 < temp_v1)
  {
    if (temp_a0)
    {
      return -1;
    }
    else
    {
      return -1;
    }
  }
  return temp_v1 < temp_a0;
}
