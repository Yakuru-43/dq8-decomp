// range: 0x359C90 0x359CF0
// Searches a fixed table of 32 records for an active one at (x, y).
// Matches with mwcps2 3.0.1 build 145/151, -O3.

struct Entry {
    int id; // < 0: slot unused
    char pad[0xC];
    short x;
    short y;
    char pad2[0x590 - 0x14];
};

Entry *FindEntry(Entry *list, int x, int y)
{
    for (int i = 0; i < 32; i++) {
        Entry *e = &list[i];
        if (e->id >= 0 && x == e->x && y == e->y)
            return e;
    }
    return 0;
}
