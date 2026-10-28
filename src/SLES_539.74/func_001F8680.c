// range: 0x1F8680 0x1F8710
#include "common.h"

extern void func_001E7420(f32, s32);
extern void func_001EA000(void *);

typedef struct {
    /* 0x00 */ void *next;
    /* 0x04 */ char pad_04[0x0C];
    /* 0x10 */ void *item;
    /* 0x14 */ char pad_14[0x20];
    /* 0x34 */ void *owner;
    /* 0x38 */ s32 flag;
    /* 0x3C */ char pad_3C[0x30];
    /* 0x6C */ void *data;
} Node;

typedef struct {
    /* 0x00 */ char pad_00[0x94];
    /* 0x94 */ Node *head;
    /* 0x98 */ char pad_98[0x04];
    /* 0x9C */ s32 count;
} List;

void func_001F8680(List *arg0) {
    Node *var_s2;
    Node *temp_s1;
    void *temp_s0;

    if (arg0->count != 0) {
        var_s2 = arg0->head;
        while (var_s2 != NULL) {
            temp_s1 = (Node *)var_s2->item;
            temp_s1->owner = arg0;
            temp_s1->flag = 0;
            temp_s0 = temp_s1->data;
            if (temp_s0 != NULL) {
                func_001E7420(1.0f, (s32)temp_s0 + 0x1F0);
                func_001EA000(temp_s0);
            }
            temp_s1->owner = NULL;
            temp_s1->flag = 0;
            var_s2 = (Node *)var_s2->next;
        }
    }
}
