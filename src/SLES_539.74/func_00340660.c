// range: 0x340660 0x340690
// permuter-artifact: contrived C, rewrite as real C++ (see CLAUDE.md)
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
s32 func_00340660(char *arg0)
{
  char **new_var;
  if ((*((u8 *) (((char *) arg0) - -0x15))) != 3)
  {
    if (arg0)
    {
      return 0;
    }
    else
    {
      return 0;
    }
  }
  return (*((u8 *) (((char *) (*(new_var = &arg0))) + 0x13))) == 0;
}
