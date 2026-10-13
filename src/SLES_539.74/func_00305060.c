// range: 0x305060 0x3050A0
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
s32 func_00305060(char *arg0, s32 arg1)
{
  s32 var_v0;
  var_v0 = (*((s32 *) (((char *) arg0) + 4))) + arg1;
  if (var_v0 < 0)
  {
    var_v0 = 0;
    arg0 = arg0;
  }
  if (var_v0 > (0xF4240 - 1))
  {
    var_v0 = 0xF423F;
  }
  *((s32 *) (((char *) arg0) + 4)) = var_v0;
  return *((s32 *) (((char *) arg0) + 4));
}
