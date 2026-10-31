// range: 0x1578D0 0x1578F0
// permuter-artifact: contrived C, rewrite as real C++ (see CLAUDE.md)
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
volatile int func_001578D0(char *arg0, s32 arg1)
{
  char *new_var;
  short pad;
  u8 new_var2;
  new_var = (char *) arg0;
  new_var2 = *((u8 *) (new_var + 0x40));
  *((u8 *) (new_var + 0x40)) = (u8) (((new_var2 & (~1)) | (arg1 & (1 & 0xFFFFFFFFu))) & 0xFFFF);
  *((u8 *) (new_var + 0x40)) = (u8) ((new_var2 & (~1)) | (arg1 & (1 & 0xFFFFFFFFu)));
}
