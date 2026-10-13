// range: 0x252210 0x252250
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
void func_00252210(char *arg0, s32 arg1, s32 arg2)
{
  char *new_var;
  *((s32 *) (((char *) arg0) + 0x1C)) = arg1;
  *((s32 *) (((char *) arg0) + 0x20)) = arg2;
  *((s32 *) (((char *) arg0) + 0x18)) = 0;
  *((s32 *) (((char *) arg0) + 0x14)) = 0;
  *((s32 *) (((char *) arg0) + 8)) = 0;
  new_var = (char *) arg0;
  *((s32 *) (new_var + 0x10)) = 0;
  *((s32 *) (new_var + 0xC)) = 0;
  *((s32 *) (new_var + 8)) = 0;
  *((s32 *) (new_var + 0xC)) = arg1;
  *((s32 *) (new_var + 0x10)) = (s32) (arg1 + arg2);
  *((char **) (new_var + 0x24)) = (char *) (arg0 + 8);
}
