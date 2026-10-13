// range: 0x308040 0x308070
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
void func_00308040(char *arg0, s32 arg1)
{
  s32 var_a1;
  unsigned int new_var;
  var_a1 = arg1;
  if (var_a1 > (0x05F5E100 - 1))
  {
    var_a1 = 0x05F5E0FF;
  }
  if (var_a1 < 0)
  {
    var_a1 = 0;
  }
  new_var = var_a1;
  *((s32 *) (((char *) arg0) + 0x5C10)) = new_var;
}
