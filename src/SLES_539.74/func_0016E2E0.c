// range: 0x16E2E0 0x16E310
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
s32 func_0016E2E0(s32 arg0, s32 arg1)
{
  int new_var;
  int new_var2;
 if (1) { new_var = arg1 >= 0; do { } while (0);
    if (new_var && (arg1 < 0x80))
    {
      new_var2 = arg1 * 8;
      return *((s32 *) (((char *) (new_var2 + arg0)) + 0x10));
    }
  }
  return 0;
}
