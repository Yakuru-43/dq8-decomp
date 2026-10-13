// range: 0x18A180 0x18A1C0
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
M2C_UNK func_00130FD0(char *, s32, M2C_UNK);
void func_0018A180(char *arg0, long long arg1, s32 arg2)
{
  *((s8 *) (((char *) arg0) - -0x6932)) = arg1;
  if ((arg1 != 0) && (arg2 != 0))
  {
    func_00130FD0(arg0 + 0x6934, arg2, 0x30);
  }
}
