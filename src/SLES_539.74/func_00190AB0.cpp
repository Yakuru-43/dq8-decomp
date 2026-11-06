// range: 0x190AB0 0x190B90
#include "common.h"

extern char *D_0040FBB0 __attribute__((section(".data")));
extern s128 D_0040FC00 __attribute__((section(".data")));
extern s128 D_0040FC40 __attribute__((section(".data")));
extern s128 D_0040FC50 __attribute__((section(".data")));
extern s128 D_0040FC60 __attribute__((section(".data")));
extern s128 D_0040FC70 __attribute__((section(".data")));
extern char D_003C3460[];
extern s32 D_003E05A0;

struct Obj {
    s32 data[0x30];
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void get_name(s128 *);
    virtual void get_desc(s128 *);
};

extern "C" {

void *func_0016DF60(void *, char *);
void func_001340C0(void *, void *);
Obj *func_001903E0(void *);
Obj *func_001903D0(void *);
void func_00190BC0(void *, s128 *);
void func_00190BB0(void *, s128 *);
s32 func_00190B90(void *);
s32 DebugPrintf(char *, ...);

void func_00190AB0(void *mgr) {
    void *r;
    Obj *obj;
    s32 count;

    r = func_0016DF60(mgr, D_0040FBB0);
    if (r != 0) {
        func_001340C0(&D_0040FC00, r);
    }
    obj = func_001903E0(mgr);
    if (obj != 0) {
        func_00190BC0(obj, &D_0040FC40);
        func_00190BB0(obj, &D_0040FC50);
    }
    count = func_00190B90(mgr);
    D_003E05A0 = count;
    DebugPrintf(D_003C3460, count);
    obj = func_001903D0(mgr);
    if (obj != 0) {
        obj->get_name(&D_0040FC60);
        obj->get_desc(&D_0040FC70);
    }
}

}
