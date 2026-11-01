// range: 0x00165760 0x00165860
#include "common.h"

typedef struct {
    u8 *str;        /* 0x00 */
    s32 len;        /* 0x04 */
} CommentText;

void func_00165760(CommentText *text) {
    u8 *str = text->str;
    s32 i;

    for (i = 0; i < text->len; ) {
        if (str[i] == '/' && str[i + 1] == '/') {
            for (; i < text->len; i++) {
                if (str[i] == '\n' || str[i] == '\r') {
                    break;
                }
                str[i] = ' ';
            }
        }
        if (str[i] == '/' && str[i + 1] == '*') {
            for (; i < text->len; i++) {
                if (str[i] == '*' && str[i + 1] == '/') {
                    str[i] = ' ';
                    str[i + 1] = ' ';
                    break;
                }
                str[i] = ' ';
            }
        } else {
            i++;
        }
    }
}
