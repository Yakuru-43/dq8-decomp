// range: 0x212790 0x2127B0
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
extern char *D_003E0944;
s32 func_00212790(void)
{
  char *new_var;
  s8 temp_v0;
  int new_var2;
  new_var = D_003E0944;
  temp_v0 = *((s8 *) (((char *) new_var) + 0x75));
  if (temp_v0 == 0)
  {
    if (D_003E0944)
    {
      return new_var2 = 1;
    }
    else
    {
      return new_var2 = 1;
    }
  }
  return temp_v0 == 2;
}
