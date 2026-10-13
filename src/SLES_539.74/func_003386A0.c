// range: 0x3386A0 0x3386E0
// auto: m2c draft with casts added + decomp-permuter, verified byte-exact

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
s32 func_001667C0();
extern s32 D_003E125C;
extern s32 *D_003E1260;
extern s32 D_003E1264;
inline int *inline_fn(int arg0)
{
  return (int *) arg0;
}

s32 func_003386A0(void)
{
  int new_var;
  D_003E1260 = inline_fn(D_003E125C + (D_003E1264 * 0x14));
  *D_003E1260 = func_001667C0(new_var);
  return 1;
  new_var = D_003E1264;
  if (new_var)
  {
  }
}
