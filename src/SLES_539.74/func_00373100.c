// range: 0x373100 0x373110
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
typedef struct 
{
  char pad0[0x20];
  u32 unk20;
} S_arg0;
long func_00373100(S_arg0 *arg0)
{
  u32 new_var;
  new_var = arg0->unk20;
  if ((arg0->unk20 && arg0->unk20) && arg0->unk20)
  {
  }
  return new_var;
}
