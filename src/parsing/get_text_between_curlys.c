/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** get_text_between_curlys
*/

#include "game.h"
#include <string.h>
#include "map.h"
#include <stdlib.h>

void get_curly_end_pointer2(char *token, int *end_pos, int *curlys)
{
    for (int i = 0; token[i] != 0; i++) {
        *end_pos += 1;
        if (token[i] == '{') {
            *curlys += 1;
        }
    }
}

char *get_curly_end_pointer(char *pos_open_curly)
{
    char *token = NULL;
    int curlys = 1;
    char *lua = strdup(pos_open_curly + 1);
    int end_pos = 0;

    token = strtok(lua, "}");
    while (token != NULL) {
        curlys -= 1;
        get_curly_end_pointer2(token, &end_pos, &curlys);
        if (curlys == 0)
            break;
        token = strtok(NULL, "}");
    }
    free(lua);
    return pos_open_curly + end_pos;
}

char *get_text_between_curlys(char *pos_open_curly)
{
    char *end_curly = get_curly_end_pointer(pos_open_curly);
    char *text = get_text_between_pointers(pos_open_curly + 1, end_curly);

    return text;
}
