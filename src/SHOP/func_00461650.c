// range: 0x461650 0x461670
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
void func_00461650(s32 arg0, s32 arg1, s32 arg2, s8 arg3)
{
  int new_var;
  new_var = arg1 * 4;
  *((s32 *) (((char *) (new_var + arg0)) + 0x48)) = arg2;
  *((s8 *) (((char *) (arg1 + arg0)) + 0x88)) = arg3;
}
