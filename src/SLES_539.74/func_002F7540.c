// range: 0x2F7540 0x2F7580
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
void func_002F7540(char *arg0, f32 fparg0)
{
  s8 *new_var;
  f32 new_var3;
  char *new_var2;
  new_var3 = fparg0;
  if (!new_var3)
  {
    *((s8 *) (((char *) arg0) + 0x18C)) = 1;
  }
  else
  {
    *((f32 *) (((char *) arg0) + 0x188)) = fparg0;
    new_var2 = (char *) arg0;
    new_var = (s8 *) (new_var2 + 0x18C);
    *new_var = 0;
    *((s8 *) (((char *) arg0) + 0x18D)) = 0;
  }
}
