// range: 0x3012B0 0x3012F0
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
inline u16 *inline_fn(char *arg0)
{
  return (u16 *) (((char *) arg0) + 2);
}

void func_003012B0(char *arg0, s8 arg1)
{
  char *temp_a1;
  char *new_var3;
  int new_var;
  char *new_var2;
  new_var2 = arg0;
  new_var3 = (char *) arg0;
  *((s8 *) (new_var3 + 0xC)) = arg1;
  temp_a1 = *((char **) (new_var3 + 0x10));
  if ((((s32) (*((u8 *) (((char *) temp_a1) + 0)))) <= 0) || ((*inline_fn(temp_a1)) == 0xFFFF))
  {
    ;
    *((s8 *) (((char *) new_var2) + 0xC)) = 0;
  }
}
