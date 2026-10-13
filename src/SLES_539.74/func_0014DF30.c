// range: 0x14DF30 0x14DF80
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
M2C_UNK func_0014DF80();
void func_0014DF30(char *arg0)
{
  short new_var2;
  s32 *new_var;
  new_var2 = (*((s32 *) (((char *) arg0) + 0x28))) != 0;
  if (new_var2)
  {
    *((s32 *) (((char *) arg0) + 0x24)) = 0;
    func_0014DF80();
    return;
  }
  *((s32 *) (((char *) arg0) + 0x2C)) = 0;
  new_var = (s32 *) (((char *) arg0) + 0x3C);
  *((s32 *) (((char *) arg0) + 0x30)) = -1;
  *new_var = 0;
  *((s32 *) (((char *) arg0) + 0x20)) = 0;
}
