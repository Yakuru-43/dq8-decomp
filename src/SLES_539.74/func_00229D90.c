// range: 0x229D90 0x229DD0
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
inline s32 inline_fn(char *arg0)
{
  return *((s32 *) (((char *) arg0) + 0x14));
}

void func_00229D90(char *arg0, s32 arg1)
{
  unsigned int new_var;
  int new_var2;
  if ((arg1 >= ((arg1 * 0x10) * 0)) && (arg1 < (*((s32 *) (((char *) arg0) + 4)))))
  {
    new_var = inline_fn(arg0);
    new_var2 = arg1 * 0x10;
    *((s32 *) (((char *) (new_var2 + new_var)) + 0xC)) = 0x3F800000;
  }
}
