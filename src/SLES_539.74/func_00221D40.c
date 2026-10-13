// range: 0x221D40 0x221D70
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
void func_00221D40(s32 arg0, s32 arg1)
{
  s32 temp_v1;
  s32 var_a2;
  int new_var;
  int new_var3;
  int new_var2;
  var_a2 = 0;
  do
  {
    new_var2 = var_a2 * 0x14;
    new_var3 = arg0 + arg1;
    temp_v1 = new_var2;
    var_a2 += 1;
    new_var = new_var3 + temp_v1;
    *((s8 *) (((char *) new_var) + 0x1838)) = 0;
  }
  while (var_a2 < ((unsigned char) 8));
}
