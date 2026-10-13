// range: 0x4682E0 0x468310
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
char *func_00468380();
s32 func_004682E0(void)
{
  char *new_var;
  char *temp_v0;
  if (1)
  {
    new_var = func_00468380();
    temp_v0 = new_var;
    if (!temp_v0)
    {
      return 0;
    }
  }
  return *((s32 *) (((char *) temp_v0) + 4));
}
