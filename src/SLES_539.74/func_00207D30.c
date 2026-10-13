// range: 0x207D30 0x207D60
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
extern volatile char D_003DFCF0;
s8 func_00207D30(s32 arg0)
{
  if (((!arg0) && (!arg0)) && (!arg0))
  {
  }
  if ((arg0 >= 0) && (arg0 < 5))
  {
    return *((&D_003DFCF0) + arg0);
  }
  return -1;
}
