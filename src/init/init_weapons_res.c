/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** init_weapons_res
*/

#include "res.h"
#include <stdlib.h>
#include <SFML/Audio.h>

static void init_weapons_res2(weapons_res_t *weapons_res)
{
    weapons_res->smg_bullet =
    sfTexture_createFromFile("res/weapons/smg_bullet.png", NULL);
    weapons_res->shotgun =
    sfTexture_createFromFile("res/weapons/shotgun.png", NULL);
    weapons_res->shotgun_bullet =
    sfTexture_createFromFile("res/weapons/shotgun_bullet.png", NULL);
    weapons_res->laser_gun =
    sfTexture_createFromFile("res/weapons/laser_gun.png", NULL);
    weapons_res->laser_gun_bullet =
    sfTexture_createFromFile("res/weapons/red_beam.png", NULL);
}

weapons_res_t *init_weapons_res(void)
{
    weapons_res_t *weapons_res = malloc(sizeof(weapons_res_t));

    weapons_res->wind_staff_bullet =
    sfTexture_createFromFile("res/weapons/wind_staff_bullet.png", NULL);
    weapons_res->wind_staff =
    sfTexture_createFromFile("res/weapons/wind_staff.png", NULL);
    weapons_res->ak47 = sfTexture_createFromFile("res/weapons/ak47.png", NULL);
    weapons_res->ak47_bullet =
    sfTexture_createFromFile("res/weapons/ak_bullet.png", NULL);
    weapons_res->tornado_col =
    sfTexture_createFromFile("res/weapons/tornado_end.png", NULL);
    weapons_res->ak47_col =
    sfTexture_createFromFile("res/weapons/ak47_end.png", NULL);
    weapons_res->smg =
    sfTexture_createFromFile("res/weapons/ump45.png", NULL);
    init_weapons_res2(weapons_res);
    return weapons_res;
}
