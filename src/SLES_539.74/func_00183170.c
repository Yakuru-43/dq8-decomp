// range: 0x183170 0x1831A0
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
extern s16 D_003E04E0;
s32 func_00183170(void)
{
  unsigned char var_a1;
  var_a1 = 1;
  if ((D_003E04E0 != 3) && (D_003E04E0 != 1))
  {
    var_a1 = 0;
  }
  return var_a1 & 0xFF;
}
