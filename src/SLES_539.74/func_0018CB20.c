// range: 0x18CB20 0x18CB50
// auto: m2c draft with casts added + decomp-permuter, verified byte-exact

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
void func_0018CB20(s32 arg0, s32 arg1, s16 arg2, s32 arg3)
{
  s32 new_var;
  char *temp_v1;
  if (!((arg1 >= 0) && (arg1 < 2)))
  {
    return;
  }
  temp_v1 = (char *) ((arg1 * 8) + (new_var = arg0));
  *((s16 *) (((char *) temp_v1) + 0x5344)) = arg2;
  *((s32 *) (((char *) temp_v1) + 0x5348)) = arg3;
}
