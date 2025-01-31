/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** enemies_take_dmg
*/

#include "game.h"
#include "enemies.h"
#include "const.h"
#include "objects.h"
#include "system.h"
#include "artefact.h"
#include "player.h"
#include "anim.h"

static void on_mob_death(game_t *game, mob_t *mob)
{
    sfVector2f mpos = sfSprite_getPosition(mob->sprite);

    mob->statut = DYING;
    mob->attack_loop = 1;
    mob->i_anim = 0;
    if (game->system->statut != COMBAT_BOSS ||
        (game->system->statut == COMBAT_BOSS && mob->type >= BOSS1)) {
        if (game->system->statut == COMBAT_BOSS && mob->type >= BOSS1)
            spawn_random_money_radius(game, mpos, 100,
                40 * game->system->floor);
        else
            spawn_random_money(game, mpos, sfTrue);
        spawn_random_weapon(game, mpos, -1);
    }
    if ((rand() % 100) + 1 <=
    (get_multiplicator_stat(LIFESTEAL, game) - 1) * 100)
        player_gain_health(game, 1);
    get_exp_from_mob(game, mob);
}

void enemy_take_dmg(game_t *game, mob_t *mob, float dmg)
{
    sfBool crit = sfFalse;

    if ((rand() % 100) + 1 <=
        (get_multiplicator_stat(COUP_CRITIQUE, game) - 1) * 100) {
            crit = sfTrue;
            dmg *= 2;
    }
    dmg *= get_multiplicator_stat(DAMAGE, game);
    mob->stats->cur_hp -= dmg;
    add_anim_to_list((&game->anims),
    get_hitmarker(dmg, sfSprite_getPosition(mob->sprite), game->res, crit));
    if (mob->stats->cur_hp <= 0) {
        on_mob_death(game, mob);
    }
}
