// range: 0x1BC2C0 0x1BC310
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
f32 func_0013BCA0(f32);
s32 func_001BC2C0(char *arg0)
{
  int new_var;
  f32 temp_f0;
  temp_f0 = func_0013BCA0(*((f32 *) (((char *) (*((char **) (((char *) arg0) + 4)))) + 4)));
  new_var = 1;
  if ((*((s32 *) (((char *) arg0) + 0))) == 3)
  {
    *((f32 *) (((char *) (*((char **) (((char *) arg0) + (4 & 0xFFFFFFFF))))) + 4)) = temp_f0;
  }
  return new_var;
}
