// range: 0x2B34E0 0x2B3520
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
extern s16 D_003E0F9C;
extern char *D_003E0FA0;
void func_002B34E0(void)
{
  char *var_a2;
  s32 var_a1;
  var_a2 = D_003E0FA0;
  var_a1 = 0;
  D_003E0F9C = 0;
  do
  {
    *((s8 *) (((char *) var_a2) + 0)) = -1;
    var_a1 += 1;
    *((s8 *) (((char *) var_a2) + 2)) = 0;
    var_a2 += 3;
  }
  while (var_a1 < 0x18C);
}
