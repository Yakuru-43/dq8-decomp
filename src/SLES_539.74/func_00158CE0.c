// range: 0x158CE0 0x158EC0
#include "common.h"

/* GS register values, as the SDK's SCE_GS_SET_* macros build them. */
#define GS_BITBLTBUF(sbp, sbw, spsm, dbp, dbw, dpsm) \
    ((u64)(sbp) | ((u64)(sbw) << 16) | ((u64)(spsm) << 24) | \
     ((u64)(dbp) << 32) | ((u64)(dbw) << 48) | ((u64)(dpsm) << 56))
#define GS_TRXPOS(ssax, ssay, dsax, dsay, dir) \
    ((u64)(ssax) | ((u64)(ssay) << 16) | ((u64)(dsax) << 32) | \
     ((u64)(dsay) << 48) | ((u64)(dir) << 59))
#define GS_TRXREG(rrw, rrh) ((u64)(rrw) | ((u64)(rrh) << 32))

/* Low and high words of a 64-bit A+D data field. */
#define LO32(v) (u32)((v) & 0xFFFFFFFFUL)
#define HI32(v) (u32)(((v) >> 32) & 0xFFFFFFFFUL)

/* Build a GS image upload: an A+D header setting BITBLTBUF, TRXPOS, TRXREG
 * and TRXDIR, then one IMAGE GIFtag per 0x7FF0-qword chunk.  Returns the
 * packet size in words. */
s32 func_00158CE0(u32 *packet, s32 dbp, s32 dpsm, s32 dbw, u32 addr, s32 qwc,
                  s32 dsax, s32 dsay, s32 rrw, s32 rrh) {
    s32 n;
    u32 *start;
    u64 reg;

    start = packet;
    packet[0] = 0x10000006;
    packet[1] = 0;
    packet[2] = 0;
    packet[3] = 0;
    packet[4] = 5;
    packet[5] = 0x10000000;
    packet[6] = 0xE;
    packet[7] = 0;
    packet[8] = 0;
    packet[9] = 0;
    packet[10] = 0x3F;
    packet[11] = 0;
    reg = GS_BITBLTBUF(0, 0, 0, dbp, dbw, dpsm);
    packet[12] = LO32(reg);
    packet[13] = HI32(reg);
    packet[14] = 0x50;
    packet[15] = 0;
    reg = GS_TRXPOS(0, 0, dsax, dsay, 0);
    packet[16] = LO32(reg);
    packet[17] = HI32(reg);
    packet[18] = 0x51;
    packet[19] = 0;
    reg = GS_TRXREG(rrw, rrh);
    packet[20] = LO32(reg);
    packet[21] = HI32(reg);
    packet[22] = 0x52;
    packet[23] = 0;
    packet[24] = 0;
    packet[25] = 0;
    packet[26] = 0x53;
    packet[27] = 0;
    packet += 28;
    while (qwc > 0) {
        n = 0x7FF0;
        if (qwc < 0x7FF0) {
            n = qwc;
        }
        packet[0] = 0x10000001;
        packet[1] = 0;
        packet[2] = 0;
        packet[3] = 0;
        packet[4] = n | 0x8000;
        packet[5] = 0x08000000;
        packet[6] = 0;
        packet[7] = 0;
        packet[8] = n | 0x30000000;
        packet[9] = addr;
        packet[10] = 0;
        packet[11] = 0;
        addr += n << 4;
        packet += 12;
        qwc -= 0x7FF0;
    }
    return packet - start;
}
