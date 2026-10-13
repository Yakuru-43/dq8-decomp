// range: 0x2B9380 0x2B93C0
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
M2C_UNK func_00131188(s32, M2C_UNK, M2C_UNK);
M2C_UNK func_001340C0(s32);
void func_002B9380(s32 arg0, s32 arg1)
{
  int new_var;
  if (arg1 != 0)
  {
    func_001340C0(arg0 + 0x50);
    if (arg0 && arg0)
    {
    }
  }
  else
  {
    new_var = arg0 + 0x50;
    func_00131188(new_var, 0, 7);
  }
}
