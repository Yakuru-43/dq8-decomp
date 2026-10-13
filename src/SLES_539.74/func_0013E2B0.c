// range: 0x13E2B0 0x13E2D0
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
inline u8 inline_fn(int arg0, int arg1)
{
  return (u8) (arg0 | (arg1 << 7));
}

void func_0013E2B0(char *arg0, s32 arg1)
{
  u8 new_var;
  new_var = *((u8 *) (arg0 + 0x70));
  *((u8 *) (((char *) arg0) + 0x70)) = inline_fn(((((((((*((u8 *) (arg0 + 0x70))) & (~0x80)) & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF, arg1 & 1);
  *((u8 *) (((char *) arg0) + 0x70)) = inline_fn(new_var & (~0x80), arg1 & 1);
}
