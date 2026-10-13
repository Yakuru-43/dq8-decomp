// range: 0x181B80 0x181BA0
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
void func_00181B80(char *arg0)
{
  unsigned char new_var2;
  char *new_var;
  s16 temp_v1;
  new_var = arg0;
  temp_v1 = *((s16 *) (new_var + 0x2FC));
  new_var2 = (unsigned char) 0;
  if (new_var2 < temp_v1)
  {
    *((s16 *) (((char *) arg0) + 0x2FC)) = (s16) (temp_v1 - 1);
  }
}
