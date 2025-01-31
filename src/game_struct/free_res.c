/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** free_res
*/

#include "res.h"
#include "sound_manager.h"
#include <stdlib.h>

static void free_player_res(player_res_t *res)
{
    sfTexture_destroy(res->dash_down);
    sfTexture_destroy(res->dash_left);
    sfTexture_destroy(res->dash_right);
    sfTexture_destroy(res->dash_up);
    sfTexture_destroy(res->idle_down);
    sfTexture_destroy(res->idle_left);
    sfTexture_destroy(res->idle_right);
    sfTexture_destroy(res->idle_up);
    sfTexture_destroy(res->move_down);
    sfTexture_destroy(res->move_left);
    sfTexture_destroy(res->move_right);
    sfTexture_destroy(res->move_up);
    free(res);
}

static void free_object_res(obj_res_t *res)
{
    sfTexture_destroy(res->pot);
    sfTexture_destroy(res->pot_explosion);
    sfTexture_destroy(res->spike);
    free(res);
}

static void free_weapons_res(weapons_res_t *res)
{
    sfTexture_destroy(res->ak47);
    sfTexture_destroy(res->ak47_bullet);
    sfTexture_destroy(res->ak47_col);
    sfTexture_destroy(res->laser_gun);
    sfTexture_destroy(res->laser_gun_bullet);
    sfTexture_destroy(res->shotgun);
    sfTexture_destroy(res->shotgun_bullet);
    sfTexture_destroy(res->smg);
    sfTexture_destroy(res->smg_bullet);
    sfTexture_destroy(res->tornado_col);
    sfTexture_destroy(res->wind_staff);
    sfTexture_destroy(res->wind_staff_bullet);
    free(res);
}

static void free_tilesets(tilesets_t *res)
{
    sfTexture_destroy(res->floor1);
    free(res);
}

static void free_projectile_mob_res(res_projectile_mob_t *res)
{
    for (int i = 0; i < NBR_PROJECTILE_COLOR; i++) {
        sfTexture_destroy(res->textures_attack_mob[i]);
    }
    free(res);
}

static void free_sbuf_list(sbuf_list_t **list)
{
    sbuf_list_t *next = NULL;

    for (; *list; *list = next) {
        next = (*list)->next;
        delete_sbuf(list, *list);
    }
}

void free_res(res_t *res)
{
    if (res == NULL)
        return;
    sfTexture_destroy(res->crosshair1);
    free_player_res(res->player_res);
    free_weapons_res(res->weapons);
    free_object_res(res->obj_res);
    free_tilesets(res->tilesets);
    free_projectile_mob_res(res->projectile_mob);
    free_mob_res(res->mob);
    free_sbuf_list(&(res->sbuf_list));
    free(res);
}
