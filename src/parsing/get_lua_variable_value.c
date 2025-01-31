/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** get_lua_variable_value
*/

#include "game.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//get basic value with comma as delimiter
char *get_lua_variable_value(char *lua, char *variable)
{
    char *pos = strstr(lua, variable);
    char value[1024] = {0};
    char *result = NULL;
    int i = 0;

    if (pos == NULL)
        printf("lua variable no found\n");
    pos = strchr(pos, '=') + 1;
    for (; *pos == ' ' || *pos == '\t'; pos++)
        continue;
    for (; pos[i] != ',' && pos[i] != '.'; i++) {
        value[i] = pos[i];
    }
    result = malloc(i + 1);
    for (int j = 0; j < i; j++) {
        result[j] = value[j];
    }
    result[i] = 0;
    return result;
}
