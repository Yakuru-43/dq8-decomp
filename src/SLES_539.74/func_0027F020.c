// range: 0x27F020 0x27F040
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
extern char *D_003E0DD4;
inline s32 *inline_fn(char *arg0, int arg1)
{
  return (s32 *) (arg0 + arg1);
}

s32 func_0027F020(void)
{
  int new_var;
  if (D_003E0DD4 == 0)
  {
    return 0;
  }
  return *inline_fn((char *) D_003E0DD4, new_var = 0x34);
}
