// range: 0x207A50 0x207A80
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
s32 func_00207A50(char *arg0, s32 arg1, s32 arg2)
{
  s32 temp_v0;
  s32 var_a1;
  var_a1 = arg1;
  if (var_a1 < 0)
  {
    var_a1 = 0;
  }
  temp_v0 = (*((s32 *) (((char *) arg0) + 8))) + arg2;
  if (temp_v0 <= var_a1)
  {
    var_a1 = temp_v0;
  }
  *((s32 *) (((char *) arg0) + 0xC)) = var_a1;
  return *((s32 *) (((char *) arg0) + 0xC));
}
