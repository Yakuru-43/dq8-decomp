// range: 0x20C5C0 0x20C8C0
// flags: -flag divbyzerocheck
// (the original guards the divide with bnez + break 0, 7: #pragma divbyzerocheck)
#include "common.h"

typedef struct {
    char pad0[0x10];
    f32 gain;   /* +0x10 */
    s32 level;  /* +0x14 */
    f32 volume; /* +0x18 */
    f32 fade;   /* +0x1C */
    s32 unk20;  /* +0x20 */
    char pad24[4];
    s32 track; /* +0x28 */
    char pad2C[0x94];
} BgmSlot;

typedef struct {
    char data[0x6C];
} BgmVoice;

typedef struct {
    char pad0[0x55F6];
    s8 suppress; /* +0x55F6 */
    char pad55F7[0x19];
    BgmSlot slots[2];   /* +0x5610 */
    BgmVoice voices[2]; /* +0x5790 */
    char pad5868[0xC];
    s32 current; /* +0x5874 */
    char pad5878[0xF69];
    u8 waiting; /* +0x67E1 */
    char pad67E2[2];
    s32 waitFrames; /* +0x67E4 */
    s32 waitTrack;  /* +0x67E8 */
    s32 waitVolume; /* +0x67EC */
} BgmPlayer;

extern void func_003727A0(BgmVoice *voice);
extern void func_00372520(BgmVoice *voice, f32 volume);
extern void func_003727D0(BgmVoice *voice);
extern void func_0025BD40(void);
extern s32 func_0013A900(f32 value);
extern void DebugPrintf(const char *fmt, ...);

extern char D_003C7740[]; /* "PlayBGM Wait:%d\n" */
extern char D_003C7760[]; /* "play_vol:%d , %f\n" */

static inline BgmSlot *CurrentSlot(BgmPlayer *player) {
    s32 index = player->current;
    if (index < 0) {
        return 0;
    }
    return &player->slots[index];
}

static inline BgmVoice *CurrentVoice(BgmPlayer *player) {
    s32 index = player->current;
    if (index < 0) {
        return 0;
    }
    return &player->voices[index];
}

static inline s32 SlotVolume(BgmSlot *slot, f32 volume) {
    s32 v = (s32)(slot->fade * (slot->gain * ((f32)slot->level * volume)));
    if (0x7F < v) {
        v = 0x7F;
    }
    return v;
}

void func_0020C5C0(BgmPlayer *player, s32 track, s32 level, s32 wait, f32 volume) {
    BgmSlot *slot;
    BgmVoice *voice;
    s32 v;
    s32 v2;
    s32 frames;
    f32 scale;

    player->waiting = 0;
    if (player->suppress != 0) {
        player->suppress = 0;
        return;
    }
    slot = CurrentSlot(player);
    if (slot->track != track) {
        BgmSlot *old = CurrentSlot(player);
        voice = CurrentVoice(player);
        if (voice != 0) {
            func_003727A0(voice);
        }
        old->track = -1;
        old->fade = 1.0f;
        old->unk20 = 0;
    }
    slot->volume = volume;
    slot->track = track;
    slot->unk20 = 0;
    if (level < 0) {
        level = 0x7F;
    }
    slot->level = level;
    func_0025BD40();
    v = SlotVolume(slot, volume);
    player->waiting = 0;
    if (0 < wait) {
        player->waiting = 1;
        frames = wait * 50 / 60;
        if (0 >= frames) {
            frames = 1;
        }
        player->waitFrames = frames;
        player->waitTrack = track;
        player->waitVolume = v;
        DebugPrintf(D_003C7740, wait);
    } else {
        slot = CurrentSlot(player);
        scale = (f32)v / 127.0f;
        slot->volume = scale;
        v2 = SlotVolume(slot, scale);
        voice = CurrentVoice(player);
        if (voice != 0) {
            func_00372520(voice, (f32)v2 / 127.0f);
        }
        func_003727D0(CurrentVoice(player));
        DebugPrintf(D_003C7760, v, func_0013A900(volume));
    }
}
