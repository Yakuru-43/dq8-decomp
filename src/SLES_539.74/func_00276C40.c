// range: 0x276C40 0x276C70
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
s32 func_00276C40(char *arg0)
{
  s32 temp_v0;
  char *temp_v0_2;
  temp_v0_2 = *((char **) (((char *) arg0) + 8));
  if (temp_v0_2 == 0)
  {
    return 0;
  }
  temp_v0 = *((s32 *) (((char *) temp_v0_2) + 0xC));
  if (!temp_v0)
  {
    return 0;
  }
  return temp_v0 + 8;
}
