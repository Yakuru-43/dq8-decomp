// range: 0x26A7F0 0x26A810
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
void func_0026A7F0(char *arg0, char *arg1)
{
  char *temp_v1;
  *((char **) (((char *) arg1) + 0xDC)) = (char *) (*((char **) (((char *) arg0) + 0x5C)));
  temp_v1 = *((char **) (((char *) arg0) + 0x5C));
  if (temp_v1 != 0)
  {
    *((char **) (((char *) temp_v1) + 0xD8)) = arg1;
  }
  arg0++;
  arg0--;
  *((char **) (((char *) arg0) + 0x5C)) = arg1;
}
