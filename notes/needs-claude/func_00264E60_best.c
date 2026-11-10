// range: 0x264E60 0x265190
#include "common.h"

typedef struct ShopItem {
    /* 0x0 */ s8 stock;
    /* 0x1 */ s8 kind;
    /* 0x2 */ s8 f2;
    /* 0x3 */ s8 limit;
    /* 0x4 */ s16 price;
    /* 0x6 */ s8 f6[2];
} ShopItem;

typedef struct PricePair {
    /* 0x0 */ s16 price1;
    /* 0x2 */ s16 price2;
} PricePair;

extern s32 D_0041FCF0 __attribute__((section(".data")));
extern s32 D_0041FCF4 __attribute__((section(".data")));
extern ShopItem D_0041FD00[] __attribute__((section(".data")));
extern PricePair D_00420500[] __attribute__((section(".data")));
extern s8 D_00420600[] __attribute__((section(".data")));

void func_00264E60(s32 arg0, s32 arg1, s32 arg2, s32 arg3, ShopItem **out,
                  s32 flags) {
    ShopItem *cursor;
    ShopItem *entry;
    ShopItem *temp;
    PricePair *pc;
    s8 *bc;
    s32 n;
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    s32 bit0;
    s32 bit1;
    s32 stock;
    s32 price;
    s32 cnt;
    s32 flag54;
    s32 idxA;
    s32 idxB;

    cursor = D_0041FD00;
    n = 0;
    i = 0;
    bit0 = flags & 1;
    bit1 = flags & 2;
    while (i < D_0041FCF0) {
        stock = cursor->stock;
        if (stock <= 0) {
            break;
        }
        if (cursor->kind != arg0) {
            goto next;
        }
        if (arg2 < cursor->limit) {
            goto next;
        }
        if (stock != arg1) {
            goto next;
        }
        price = cursor->price;
        if (price <= 0) {
            goto next;
        }
        if (bit0 == 0) {
            if (price < 0x2BA) {
                goto next;
            }
        }
        if (bit1 == 0) {
            if (!(price < 0x7D1)) {
                goto next;
            }
        }
        out[n] = cursor;
        n++;
    next:
        i++;
        cursor++;
    }
    j = 0;
    while (j < n) {
        entry = out[j];
        price = entry->price;
        cnt = D_0041FCF4;
        pc = D_00420500;
        bc = D_00420600;
        k = 0;
        while (k < cnt) {
            if (arg0 == *bc) {
                if (pc->price1 == price) {
                    goto pair;
                }
            }
            k++;
            pc++;
            bc++;
        }
        pc = 0;
    pair:
        if (pc != 0) {
            k = 0;
            while (k < n) {
                if (out[k]->price == pc->price2) {
                    out[k] = entry;
                    break;
                }
                k++;
            }
            m = j;
            while (m < n) {
                out[m] = out[m + 1];
                m++;
            }
            out[n] = 0;
            n--;
        }
        j++;
    }
    flag54 = (arg3 < 0x36);
    m = 0;
    while (m < n) {
        if (out[m]->price == 0x139) {
            if (arg0 == 1) {
                if (flag54 == 0) {
                    i = 0;
                    cursor = D_0041FD00;
                    while (i < D_0041FCF0) {
                        if (cursor->kind == 1) {
                            if (cursor->price == 0x208) {
                                goto item;
                            }
                        }
                        i++;
                        cursor++;
                    }
                    cursor = 0;
                item:
                    if (cursor != 0) {
                        out[m] = cursor;
                    }
                    return;
                }
            }
        }
        m++;
    }
    idxA = 0;
    while (idxA < n) {
        if (out[idxA]->price == 0x809) {
            goto a_found;
        }
        idxA++;
    }
    idxA = -1;
a_found:
    idxB = 0;
    while (idxB < n) {
        if (out[idxB]->price == 0x80A) {
            goto b_found;
        }
        idxB++;
    }
    idxB = -1;
b_found:
    if (idxA < 0) {
        return;
    }
    if (idxB < 0) {
        return;
    }
    if (!(idxB < idxA)) {
        return;
    }
    temp = out[idxB];
    out[idxB] = out[idxA];
    out[idxA] = temp;
}
