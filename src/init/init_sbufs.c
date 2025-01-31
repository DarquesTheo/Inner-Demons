/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** init_sbufs
*/

#include "game.h"
#include "res.h"

static void init_sbufs2(game_t *game)
{
    add_sbuf(game, "res/sfx/pot_break.ogg", "pot");
    add_sbuf(game, "res/sfx/pot_long_break.ogg", "pot_long");
    add_sbuf(game, "res/sfx/cube_break.ogg", "cube");
    add_sbuf(game, "res/sfx/cube_break.ogg", "barrel");
    add_sbuf(game, "res/sfx/game_start.ogg", "game_start");
    add_sbuf(game, "res/sfx/player_hurt.ogg", "player_hurt");
    add_sbuf(game, "res/sfx/lose.ogg", "lose1");
}

void init_sbufs(game_t *game)
{
    add_sbuf(game, "res/sfx/tick1.ogg", "tick");
    add_sbuf(game, "res/weapons/scream.ogg", "scream_test");
    add_sbuf(game, "res/sfx/smg.ogg", "smg_shoot");
    add_sbuf(game, "res/sfx/smg1.ogg", "smg_shoot1");
    add_sbuf(game, "res/sfx/smg2.ogg", "smg_shoot2");
    add_sbuf(game, "res/sfx/smg2.ogg", "smg_shoot3");
    add_sbuf(game, "res/sfx/shotgun.ogg", "shotgun_shoot");
    add_sbuf(game, "res/sfx/ak47.ogg", "ak47_shoot");
    add_sbuf(game, "res/sfx/laser_gun.ogg", "laser_gun_shoot");
    add_sbuf(game, "res/sfx/dash.ogg", "dash");
    add_sbuf(game, "res/sfx/cannon_shoot.ogg", "cannon_shoot");
    add_sbuf(game, "res/sfx/cannon_explosion.ogg", "cannon_explosion");
    add_sbuf(game, "res/sfx/arte_lvl_up.ogg", "artefact_lvl_up");
    add_sbuf(game, "res/sfx/take_dmg_soft.ogg", "player_take_dmg");
    add_sbuf(game, "res/sfx/coin_pick.ogg", "pick_coin");
    add_sbuf(game, "res/sfx/coin_drop.ogg", "drop_coin");
    init_sbufs2(game);
}
