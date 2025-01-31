/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** get_default_col
*/

#include "anim.h"
#include <stdlib.h>

col_t *get_default_col(void)
{
    col_t *col = malloc(sizeof(col_t));

    col->player = sfFalse;
    col->ennemy = sfFalse;
    col->map = sfFalse;
    col->object = sfFalse;
    col->player_proj = sfFalse;
    col->sfx = NULL;
    col->hit_list = NULL;
    return col;
}
