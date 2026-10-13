// range: 0x305020 0x305060
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
s32 func_00305020(char *arg0, s32 arg1)
{
  char *new_var;
  s32 var_v0;
  new_var = (char *) arg0;
  var_v0 = (*((s32 *) (new_var + 8))) + arg1;
  if (var_v0 < 0)
  {
    var_v0 = 0;
  }
  if (var_v0 > (0xF4240 - 1))
  {
    var_v0 = 0xF423F;
  }
  *((s32 *) (new_var + 8)) = var_v0;
  return *((s32 *) (new_var + 8));
}
