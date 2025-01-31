/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** init_tex_list
*/

#include "res.h"

void init_tex_list(game_t *game)
{
    add_tex(game, "res/enemies/projectile/projectile_mob/col.png", "mob_col");
    add_tex(game, "res/weapons/canon.png", "canon");
    add_tex(game, "res/weapons/canon_bullet.png", "canon_bullet");
    add_tex(game, "res/weapons/canon_col.png", "canon_col");
    add_tex(game, "res/money/silver.png", "silver_coin");
    add_tex(game, "res/money/gold.png", "gold_coin");
    add_tex(game, "res/money/ruby.png", "ruby_coin");
    add_tex(game, "res/money/copper.png", "copper_coin");
    add_tex(game, "res/money/copper.png", "copper_coin");
    add_tex(game, "res/map/objects/torch.png", "torch");
    add_tex(game, "res/map/objects/barrel.png", "barrel");
    add_tex(game, "res/map/objects/cube.png", "cube");
    add_tex(game, "res/map/objects/pot_long.png", "pot_long");
    add_tex(game, "res/map/objects/candle.png", "candle");
    add_tex(game, "res/map/objects/dcandle.png", "dcandle");
    add_tex(game, "res/map/objects/pot.png", "pot");
    add_tex(game, "res/npc/mage.png", "npc_mage");
}
