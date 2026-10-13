// range: 0x1CB880 0x1CB8D0
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
char *func_00181420();
s32 func_001CB880(char *arg0)
{
  char *temp_v0;
  char *new_var;
  s32 new_var2;
  new_var = (char *) arg0;
  temp_v0 = func_00181420();
  if (temp_v0 == 0)
  {
    return 0;
  }
  new_var2 = (s32) (*((s32 *) (((char *) temp_v0) + 0x10)));
  if ((*((s32 *) (new_var + 0))) == 3)
  {
    *((s32 *) (((char *) (*((char **) (new_var + 4)))) + 4)) = new_var2;
  }
  return 1;
}
