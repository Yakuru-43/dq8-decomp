// range: 0x31E420 0x31E440
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
char *func_0031E420(char *arg0)
{
  char *new_var;
  char *new_var3;
  char *new_var2;
  new_var2 = arg0;
  new_var3 = (char *) new_var2;
  if ((*((s32 *) (((char *) new_var2) + 0x58))) != 1)
  {
    new_var = new_var3;
    return *((char **) (new_var + 8));
  }
  new_var3 = arg0 + 0xC;
  return new_var3;
}
