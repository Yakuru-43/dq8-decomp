// range: 0x270C70 0x270CB0
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
M2C_UNK func_0026ABA0(s32);
s32 *func_00271C00(s32);
void func_00270C70(s32 arg0, s32 arg1)
{
  volatile int sp1C;
  s32 *temp_v0;
  s32 var_a0;
  sp1C = arg1;
  temp_v0 = func_00271C00(arg0 + 0xB0);
  if (!temp_v0)
  {
    var_a0 = 0;
  }
  else
  {
    var_a0 = *temp_v0;
  }
  func_0026ABA0(var_a0);
}
