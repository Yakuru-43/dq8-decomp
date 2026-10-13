// range: 0x259110 0x259150
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
extern char *D_003E0BC4;
void func_00259110(void)
{
  char *var_a1;
  s32 var_a0;
  var_a1 = D_003E0BC4;
  if (var_a1 != 0)
  {
    var_a0 = 0;
    do
    {
      *((s8 *) (((char *) var_a1) + 0)) = 0;
      var_a0 += 1;
      *((s32 *) (((char *) var_a1) + 0x10)) = 0;
      *((s32 *) (((char *) var_a1) + 0x14)) = 0;
      var_a1 += 0x18;
    }
    while (var_a0 < 0x18);
  }
}
