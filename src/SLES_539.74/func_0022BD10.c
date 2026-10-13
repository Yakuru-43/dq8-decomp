// range: 0x22BD10 0x22BD40
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
extern s16 D_003E00A0;
void func_0022BD10(char *arg0)
{
  int new_var;
  char *new_var2;
  char *new_var3;
  new_var2 = arg0;
  new_var3 = (char *) new_var2;
  *((s32 *) (new_var3 + 4)) = (s32) ((*((s32 *) (new_var3 + 4))) + 1);
  new_var = D_003E00A0 * 0x10;
  if (new_var <= (*((s32 *) (new_var3 + 4))))
  {
 do { *((s32 *) (((char *) new_var2) + 4)) = 0; } while (0);
  }
}
