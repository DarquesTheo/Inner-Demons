/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** init_intrect
*/

#include <SFML/Graphics.h>

sfIntRect init_intrect(int width, int height)
{
    sfIntRect rect = {0, 0, width, height};

    return rect;
}
