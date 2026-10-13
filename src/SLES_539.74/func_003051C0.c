// range: 0x3051C0 0x305200
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
s32 func_003051C0(char *arg0, s32 arg1)
{
  s32 var_v0;
  var_v0 = (*((s32 *) (((char *) arg0) + 0x1C))) + arg1;
  if (var_v0 < 0)
  {
    var_v0 = 0;
  }
  if (var_v0 > (0x05F5E100 - 1))
  {
    var_v0 = 0x05F5E0FF;
  }
  *((s32 *) (((char *) arg0) + 0x1C)) = var_v0;
  return *((s32 *) (((char *) arg0) + 0x1C));
}
