// range: 0x1A2190 0x1A21C0
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
s32 func_0018D7D0(s32, s32);
extern s32 D_003E0664;
s32 func_001A2190(int arg0)
{
  if (!D_003E0664)
  {
    return 0;
  }
  return func_0018D7D0(D_003E0664, arg0);
}
