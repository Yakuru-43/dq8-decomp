// range: 0x25D050 0x25D230
#include "common.h"

typedef struct SndQueue {
    u8 pad0[0xC];
    s32 sema;           /* 0x0C */
    u8 pad10[0x40];
    u8 byteFull;        /* 0x50 */
    s32 byteRead;       /* 0x54 */
    s32 byteWrite;      /* 0x58 */
    u8 byteData[0x18];  /* 0x5C */
    u8 pad74[8];
    u8 vecFull;         /* 0x7C */
    s32 vecRead;        /* 0x80 */
    s32 vecWrite;       /* 0x84 */
    f32 vecData[4][4];  /* 0x88 */
} SndQueue;             /* 0xC8 bytes */

extern f32 D_003DF3AC;
extern s8 D_003DFE94;

s32 WaitSema(s32);
s32 SignalSema(s32);

s32 func_0025D050(SndQueue *q, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    s32 *sema = &q->sema;
    f32 *slot;
    s32 sentA;
    s32 sentB;

    if (arg1 < D_003DF3AC) {
        return 0;
    }
    if (*sema > 0) {
        WaitSema(*sema);
    }
    sentA = 0;
    if (q->vecFull != 0 || q->vecRead != q->vecWrite) {
        slot = q->vecData[q->vecWrite];
        slot[0] = arg1;
        slot[1] = arg4;
        slot[2] = arg3;
        slot[3] = arg2;
        q->vecWrite = (q->vecWrite + 1) & 3;
        q->vecFull = 0;
        sentA = 1;
    }
    if (sentA == 0) {
        if (*sema > 0) {
            SignalSema(*sema);
        }
        return 0;
    }
    sentB = 0;
    if (q->byteFull != 0 || q->byteRead != q->byteWrite) {
        q->byteData[q->byteWrite] = D_003DFE94;
        q->byteWrite = (q->byteWrite + 1) % 24;
        q->byteFull = 0;
        sentB = 1;
    }
    if (sentB != 0) {
        if (*sema > 0) {
            SignalSema(*sema);
        }
        return 1;
    }
    if (q->vecFull == 0 || q->vecRead != q->vecWrite) {
        q->vecRead = (q->vecRead + 1) & 3;
        if (q->vecRead == q->vecWrite) {
            q->vecFull = 1;
        }
    }
    if (*sema > 0) {
        SignalSema(*sema);
    }
    return 0;
}
