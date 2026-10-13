// range: 0x13E320 0x13E340
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
void func_0013E320(char *arg0, s32 arg1)
{
  unsigned int new_var;
  new_var = *((u8 *) (((char *) arg0) + 0x70));
  new_var = (new_var & (~0x10)) | ((arg1 & 1) * 0x10);
  *((u8 *) (((char *) arg0) + 0x70)) = (u8) new_var;
}
