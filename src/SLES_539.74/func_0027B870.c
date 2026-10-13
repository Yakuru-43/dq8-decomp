// range: 0x27B870 0x27B8A0
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
s32 func_0027B870(char *arg0)
{
  unsigned int var_v0;
  var_v0 = 0;
  var_v0 = ((*((s16 *) (((char *) arg0) + 0))) > 0) != var_v0;
  if (var_v0 != 0)
  {
    var_v0 = (*((u8 *) (((char *) arg0) + 4))) == 1;
  }
  return var_v0 & 0xFF;
}
