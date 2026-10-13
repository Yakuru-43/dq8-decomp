// range: 0x1D1D30 0x1D1D70
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
M2C_UNK func_001D1700(s32);
void func_001D1D30(s32 *arg0)
{
  s32 temp_a1;
  int new_var2;
  s32 new_var;
  ;
 new_var2 = 1; if (new_var2 == (*arg0)) {
    new_var = temp_a1;
    new_var2 = new_var;
    func_001D1700(new_var2);
  }
}
