// range: 0x18E740 0x18E770
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
char *func_0018E770();
s8 func_0018E740(void)
{
  char *temp_v0;
  int new_var;
  temp_v0 = func_0018E770();
  if (!temp_v0)
  {
    new_var = 0;
    return new_var;
  }
  return *((s8 *) (((char *) temp_v0) + 2));
}
