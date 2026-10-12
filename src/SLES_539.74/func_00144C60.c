// range: 0x144C60 0x144C70
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
inline char *inline_fn(char *arg0)
{
  return (char *) (*((char **) (((char *) arg0) + 0x270)));
}

void func_00144C60(char *arg0, s128 *arg1)
{
  char *new_var;
  new_var = inline_fn(arg0);
  if (1)
  {
    *((s128 *) (new_var + 0x160)) = (s128) (*arg1);
  }
}
