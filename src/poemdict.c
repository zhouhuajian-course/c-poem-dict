/**
 * 诗词字典
 *
 * author: zhouhuajian
 * version: v1.0
 */

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "hash.h"

struct poem {
    char *title;
    char *author;
    char *content;
};

struct poem poems[8] = {
    // {"武陵春·春晚", "李清照", "风住尘香花已尽，日晚倦梳头。物是人非事事休，欲语泪先流。闻说双溪春尚好，也拟泛轻舟。只恐双溪舴艋舟，载不动许多愁。"},
    // {"如梦令·昨夜雨疏风骤", "李清照", "昨夜雨疏风骤，浓睡不消残酒。试问卷帘人，却道海棠依旧。知否，知否？应是绿肥红瘦。"},
    {NULL,    NULL,  NULL},
    {NULL,    NULL,  NULL},
    {"poem1", "李清照", "风住尘香花已尽，日晚倦梳头。物是人非事事休，欲语泪先流。闻说双溪春尚好，也拟泛轻舟。只恐双溪舴艋舟，载不动许多愁。"},
    {"poem2", "李清照", "昨夜雨疏风骤，浓睡不消残酒。试问卷帘人，却道海棠依旧。知否，知否？应是绿肥红瘦。"},
    {NULL,    NULL,  NULL},
    {NULL,    NULL,  NULL},
    {NULL,    NULL,  NULL},
    {NULL,    NULL,  NULL},
};

int arrlen = sizeof(poems) / sizeof(struct poem);

int str2idx(char *str) {
    return BKDRHash(str) % arrlen;
}

int main() {
    int idx;
    char poem_title[128];

    while (1) {
        printf(">> ");
        fgets(poem_title, 128, stdin);

        if (*poem_title == '\n') {
            continue;
        }
        // 0 1 2 3  4
        // a b c \n \0
        // strlen(poem_title) 4
        poem_title[strlen(poem_title) - 1] = '\0';

        if (strcasecmp(poem_title, "exit") == 0 || strcasecmp(poem_title, "quit") == 0) {
            break;
        }

        idx = str2idx(poem_title);
        if (!poems[idx].title || strcasecmp(poems[idx].title, poem_title) != 0) {
            printf("Unkowned poem\n");
            continue;
        }
        // 输出诗句
        printf("%s\n", poems[idx].content);
    }
    return 0;
}
