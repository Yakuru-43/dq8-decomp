// range: 0x1D6CD0 0x1D6CE0
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
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
typedef s64 M2C_UNK64;
s32 func_001D6CD0(s32 arg0)
{
  int new_var;
  new_var = (arg0 >= 0xE10) & ((unsigned int) (0xFF & 0xFFFF));
  return new_var;
}
