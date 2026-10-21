// range: 0x467040 0x467060
// auto: m2c draft + decomp-permuter, verified byte-exact
// permuter-artifact

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
s32 func_00467040(char *arg0)
{
  s16 *new_var;
  if (!(*((s8 *) (((char *) arg0) + 0))))
  {
    return 0;
  }
  new_var = (s16 *) (((char *) arg0) + 2);
  return (*new_var) != 0;
}
