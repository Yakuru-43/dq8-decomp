// range: 0x14E320 0x14E360
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
inline s32 inline_fn(s32 arg0)
{
  return arg0;
}

void func_0014E320(char *arg0)
{
  char *new_var;
  char *temp_a2;
  temp_a2 = *((char **) (((char *) arg0) + 0x38));
  if (temp_a2 != 0)
  {
    *((s32 *) (((char *) temp_a2) + 8)) = (s32) ((*((s32 *) (((char *) temp_a2) + 8))) + inline_fn(*((s32 *) (((char *) arg0) + 0x2C))));
    new_var = (char *) arg0;
    *((char **) (new_var + 0x38)) = 0;
    *((s32 *) (0x28 + new_var)) = 0;
    *((s32 *) (new_var + 0x34)) = 0;
    *((s32 *) (new_var + 0x2C)) = 0;
  }
}
