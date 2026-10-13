// range: 0x1821B0 0x182200
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
s32 func_00182F50();
s32 func_003530B0();
extern s32 D_003DFC74;
extern s32 D_003DFC78;
extern s32 D_003DFC7C;
s32 func_001821B0(void)
{
  if (func_00182F50() != 0)
  {
    return D_003DFC78;
  }
  if (!func_003530B0())
  {
    return D_003DFC74;
  }
  return D_003DFC7C;
}
