// range: 0x2827F0 0x282810
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
s32 func_002827F0(char *arg0)
{
  s32 new_var;
  char *temp_v1;
  temp_v1 = *((char **) (arg0 + 0x14));
  if (temp_v1 == 0)
  {
    return 0;
  }
  new_var = *((s32 *) (((char *) temp_v1) + 0x10));
  *((char **) ((0, ((char *) arg0) + 0x14))) = (char *) (*((char **) (((char *) temp_v1) + 0)));
  return new_var;
}
