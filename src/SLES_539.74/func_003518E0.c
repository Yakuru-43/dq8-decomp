// range: 0x3518E0 0x351910
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
extern s16 D_003E13AC;
extern s16 D_003E13B0;
void func_003518E0(s16 arg0)
{
  int new_var;
  new_var = arg0;
  D_003E13AC = new_var;
  new_var = 1;
  D_003E13B0 = new_var;
  if (D_003E13AC < 0)
  {
    D_003E13B0 = 0;
  }
}
