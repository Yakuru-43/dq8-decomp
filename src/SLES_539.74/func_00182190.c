// range: 0x182190 0x1821B0
// permuter-artifact: contrived C, rewrite as real C++ (see CLAUDE.md)
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
extern M2C_UNK D_003DFC80;
inline int inline_fn(s32 arg0)
{
  return !arg0;
}

s32 func_00182190(s32 arg0)
{
  unsigned int new_var;
  int new_var2;
  M2C_UNK *new_var3;
  new_var2 = ((unsigned char) ((0, arg0))) * 4;
  new_var2 = arg0;
  if (inline_fn(new_var2))
  {
  }
  new_var3 = &D_003DFC80;
  new_var = new_var2;
  return *(new_var3 + new_var);
}
