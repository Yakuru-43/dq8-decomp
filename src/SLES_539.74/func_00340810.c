// range: 0x340810 0x340840
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
s32 func_00340810(char *arg0)
{
  unsigned short var_a0;
  u8 temp_v1;
  temp_v1 = *((u8 *) (((char *) arg0) + 0x13));
  var_a0 = 1;
  if ((temp_v1 != 2) && (temp_v1 != 0x42))
  {
    var_a0 = 0;
  }
  return var_a0 & 0xFF;
}
