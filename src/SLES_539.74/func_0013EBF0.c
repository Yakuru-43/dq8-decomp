// range: 0x13EBF0 0x13EC20
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
void func_0013EBF0(char *arg0, s32 arg1, s32 arg2)
{
  char *temp_a2;
  temp_a2 = *((char **) (((char *) arg0) + 0xF4));
  *((s64 *) (((char *) temp_a2) + 0)) = (s64) ((arg1 * 0x10) | (((long long) (arg2 * 0x10)) << 0x10));
  *((s64 *) (((char *) temp_a2) + 8)) = 3;
  *((char **) (((char *) arg0) + 0xF4)) = (char *) ((*((char **) (((char *) arg0) + 0xF4))) + 0x10);
}
