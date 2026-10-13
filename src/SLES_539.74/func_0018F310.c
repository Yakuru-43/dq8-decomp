// range: 0x18F310 0x18F340
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
char *func_0018F3F0();
s64 func_0018F310(void)
{
  s8 *new_var;
  char *temp_v0;
  s8 *new_var2;
 do { temp_v0 = func_0018F3F0(); } while (0);
  if (temp_v0 == ((unsigned short) 0))
  {
    return 0;
  }
  new_var = &(*((s8 *) (((char *) temp_v0) + 0x16)));
  new_var2 = &(*new_var);
  return ((s64) (((s64) (*new_var2)) << 0x38)) >> 0x39;
}
