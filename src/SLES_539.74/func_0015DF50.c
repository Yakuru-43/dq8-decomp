// range: 0x15DF50 0x15DF70
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
extern char *D_003E0298;
inline s32 *inline_fn(int arg0, char *arg1)
{
  return *((s32 **) (arg0 + ((char *) arg1)));
}

void func_0015DF50(s32 arg0)
{
  s32 *var_v1;
  if (D_003E0298 == 0)
  {
    var_v1 = 0;
  }
  else
  {
    var_v1 = inline_fn(0xF20, D_003E0298);
  }
  *var_v1 = arg0;
}
