// range: 0x17B2E0 0x17B320
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
M2C_UNK func_001D7AB0(M2C_UNK);
extern s8 D_003DFC0C;
void func_0017B2E0(void)
{
  if (0 <= D_003DFC0C)
  {
    func_001D7AB0(0);
    D_003DFC0C = -1;
  }
}
