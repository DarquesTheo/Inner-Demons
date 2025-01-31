/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** init_fonts
*/

#include "res.h"

fonts_t *init_fonts(void)
{
    fonts_t *new = malloc(sizeof(fonts_t));

    new->dialogue_font =
    sfFont_createFromFile("res/fonts/main_font.ttf");
    return new;
}
