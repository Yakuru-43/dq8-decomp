// range: 0x24B770 0x24B7B0
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
volatile long long func_0024B770(s8 *arg0, s32 arg1)
{
  if ((arg1 >= 0) && (arg1 < 3))
  {
    return (((s64) (((s64) (*arg0)) << 0x38)) >> 0x3A) & (2 << arg1);
  }
  return 0;
}
