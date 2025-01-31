/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** get_text_between_pointers
*/

#include "game.h"
#include <string.h>
#include <stdlib.h>

//returns allocated text between two pointers
char *get_text_between_pointers(char *start_ptr, char *end_ptr)
{
    int length = end_ptr - start_ptr;
    char *text = malloc(length + 1);

    if (length < 1)
        return NULL;
    strncpy(text, start_ptr, length);
    text[length] = 0;
    return text;
}
