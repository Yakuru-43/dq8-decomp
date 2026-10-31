// range: 0x169EB0 0x16A0F0
#include "common.h"

typedef struct S_1695B0 {
    /* 0x00 */ struct S_1695B0 *field_00;
    /* 0x04 */ struct S_1695B0 *field_04;
    /* 0x08 */ u8 pad_08[4];
    /* 0x0C */ s32 field_0C;
} S_1695B0;

void func_001007A0(void *);
void func_00107D30(void *, s32);
s32 func_0016A1A0(s32);
void func_0016A170(s32, s32);
s32 func_0016A160(s32);
void func_0016A150(s32, void *, s32);
void func_0016A0F0(void *, s32);

void func_00169EB0(s32 arg0, S_1695B0 *arg1) {
    S_1695B0 *node;
    S_1695B0 *child;
    S_1695B0 *grand;
    s32 h;
    void *sub;

    node = arg1->field_00;
    if (node != 0) {
        child = node->field_00;
        if (child != 0) {
            grand = child->field_00;
            if (grand != 0) {
                func_00169EB0(arg0, grand);
            }
            grand = child->field_04;
            if (grand != 0) {
                func_00169EB0(arg0, grand);
            }
            h = func_0016A1A0(arg0);
            func_0016A170(h, (s32)child + 0xC);
            h = func_0016A160(arg0);
            func_0016A150(h, child, 1);
        }
        child = node->field_04;
        if (child != 0) {
            grand = child->field_00;
            if (grand != 0) {
                func_00169EB0(arg0, grand);
            }
            grand = child->field_04;
            if (grand != 0) {
                func_00169EB0(arg0, grand);
            }
            h = func_0016A1A0(arg0);
            func_0016A170(h, (s32)child + 0xC);
            h = func_0016A160(arg0);
            func_0016A150(h, child, 1);
        }
        func_0016A1A0(arg0);
        func_0016A0F0(&node->field_0C, -1);
        func_0016A160(arg0);
        func_001007A0(node);
    }
    node = arg1->field_04;
    if (node != 0) {
        child = node->field_00;
        if (child != 0) {
            grand = child->field_00;
            if (grand != 0) {
                func_00169EB0(arg0, grand);
            }
            grand = child->field_04;
            if (grand != 0) {
                func_00169EB0(arg0, grand);
            }
            h = func_0016A1A0(arg0);
            func_0016A170(h, (s32)child + 0xC);
            h = func_0016A160(arg0);
            func_0016A150(h, child, 1);
        }
        child = node->field_04;
        if (child != 0) {
            grand = child->field_00;
            if (grand != 0) {
                func_00169EB0(arg0, grand);
            }
            grand = child->field_04;
            if (grand != 0) {
                func_00169EB0(arg0, grand);
            }
            h = func_0016A1A0(arg0);
            func_0016A170(h, (s32)child + 0xC);
            h = func_0016A160(arg0);
            func_0016A150(h, child, 1);
        }
        func_0016A1A0(arg0);
        func_0016A0F0(&node->field_0C, -1);
        func_0016A160(arg0);
        func_001007A0(node);
    }
    sub = &arg1->field_0C;
    if (sub != 0) {
        func_00107D30(sub, -1);
    }
    func_001007A0(arg1);
}
