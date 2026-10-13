// range: 0x1643E0 0x164410
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
s32 func_001643E0(char *arg0)
{
  if (!(*((s32 *) (((char *) arg0) + 0x25C))))
  {
    return (~(*((s32 *) (((char *) arg0) + 4)))) & (*((s32 *) (((char *) arg0) + 0x64)));
  }
  return 0;
}
