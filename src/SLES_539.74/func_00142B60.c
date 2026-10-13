// range: 0x142B60 0x142B90
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
s32 func_00142B60(char *arg0, s32 *arg1)
{
  char *new_var2;
  int new_var;
  char *temp_v1;
  new_var = !arg0;
  if ((*((s32 *) (((char *) arg0) + 0xF20))) == 0)
  {
    return 0;
  }
  if (new_var)
  {
    arg1++;
    arg1--;
  }
  temp_v1 = *((char **) (((char *) arg0) + 0x36B0));
  new_var2 = (char *) temp_v1;
  *arg1 = *((s32 *) (new_var2 + 0));
  return *((s32 *) (((char *) temp_v1) + 4));
}
