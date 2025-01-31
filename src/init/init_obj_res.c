/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** init_obj_res
*/

#include "res.h"
#include <stdlib.h>

obj_res_t *init_obj_res(void)
{
    obj_res_t *obj_res = malloc(sizeof(obj_res_t));

    obj_res->pot =
    sfTexture_createFromFile("res/map/objects/pot.png", NULL);
    obj_res->spike =
    sfTexture_createFromFile("res/map/objects/spike.png", NULL);
    obj_res->pot_explosion =
    sfTexture_createFromFile("res/map/objects/pot_explosion.png", NULL);
    obj_res->portal_blue =
    sfTexture_createFromFile("res/map/objects/portal_blue.png", NULL);
    return obj_res;
}
