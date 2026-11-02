// range: 0x21DFE0 0x21E190
#include "common.h"

typedef struct {
    s32 name;
    u8 pad04[0x20];
} Item;

typedef struct {
    s32 count;
    Item *items;
    s32 name;
    u8 pad0C[8];
} Group;

typedef struct {
    s32 count;
    Group *groups;
} GroupList;

typedef struct {
    u8 pad00[4];
    Item *item;
    u8 pad08[4];
    Group *group;
} Selection;

extern s32 func_00166760(char *);
extern s32 func_00133F78(s32, s32);
extern GroupList *D_003E09D4;
extern Selection *D_003E09DC;

static inline Group *find_group(s32 name) {
    s32 index;
    s32 i;
    Group *g;
    GroupList *list;

    list = D_003E09D4;
    g = list->groups;
    if (name == 0) {
        index = -1;
    } else {
        for (i = 0; i < list->count; i++, g++) {
            if (g->name != 0 && func_00133F78(name, g->name) == 0) {
                index = i;
                goto found;
            }
        }
        index = -1;
    }
found:
    if (index >= 0 && list->count > index) {
        return &list->groups[index];
    }
    return 0;
}

static inline s32 find_item(Group *group, s32 name) {
    Item *it;
    s32 i;

    if (name == 0) {
        return -1;
    }
    it = group->items;
    for (i = 0; i < group->count; i++, it++) {
        if (it->name != 0 && func_00133F78(name, it->name) == 0) {
            return i;
        }
    }
    return -1;
}

static inline Item *get_item(Group *group, s32 i) {
    if (i >= 0 && group->count > i) {
        return &group->items[i];
    }
    return 0;
}

s32 func_0021DFE0(char *arg0, s32 arg1) {
    s32 group_name;
    GroupList *list;
    s32 item_name;
    Group *group;
    Item *item;
    Selection *sel;

    if (D_003E09DC == 0) {
        return 0;
    }
    if (arg1 < 2) {
        return 0;
    }
    group_name = func_00166760(arg0);
    item_name = func_00166760(arg0 + 8);
    group = find_group(group_name);
    if (group == 0) {
        return 0;
    }
    item = get_item(group, find_item(group, item_name));
    if (item == 0) {
        return 0;
    }
    sel = D_003E09DC;
    sel->item = item;
    sel->group = group;
    return 1;
}
