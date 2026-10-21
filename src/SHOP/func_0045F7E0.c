// range: 0x45F7E0 0x45F820
// auto: m2c draft + decomp-permuter, verified byte-exact
// permuter-artifact

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
M2C_UNK func_0045F820(s16);
s32 func_00465040();
void func_0045F7E0(void)
{
  int new_var;
  new_var = func_00465040() * 2;
  func_0045F820(*((s16 *) (((char *) (new_var + (*((s32 *) 0x415EA4)))) + 0xC)));
}
