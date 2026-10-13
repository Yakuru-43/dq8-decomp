// range: 0x2060B0 0x2060F0
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
void func_002060B0(char *arg0, s32 arg1)
{
  u16 *new_var;
  if ((arg1 >= 0) && (arg1 < 4))
  {
    new_var = (u16 *) (((char *) arg0) + 0x14);
    *new_var = (u16) ((*new_var) & ((~(1 << arg1)) & 0xFFFF));
  }
}
