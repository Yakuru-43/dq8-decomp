// range: 0x31E470 0x31E490
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
s32 func_0031E470(char *arg0)
{
  s32 *new_var;
  int new_var3;
  int new_var2;
  new_var = (s32 *) (((char *) arg0) + 0);
  if ((*((s32 *) (((0, (char *) arg0)) + 0x58))) != 1)
  {
    new_var2 = *new_var;
    new_var3 = new_var2;
    return new_var3;
  }
  return *((s32 *) (((char *) arg0) + 4));
}
