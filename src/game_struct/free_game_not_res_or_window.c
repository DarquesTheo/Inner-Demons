/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** free_game_not_res_or_window
*/

#include "game.h"
#include "sound_manager.h"
#include "res.h"
#include "clock.h"
#include "player.h"
#include "anim.h"
#include "map.h"
#include "system.h"
#include <stdlib.h>
#include "ui.h"

static void free_system(game_t *game)
{
    if (game->system == NULL)
        return;
    sfClock_destroy(game->system->clock);
    sfMusic_destroy(game->system->music_manager);
    save(game->system->game_time);
    sfClock_destroy(game->system->game_time);
    free(game->system);
}

static void free_sound_manager(sound_manager_t **sound_manager)
{
    sound_manager_t *next = NULL;

    for (; *sound_manager; (*sound_manager) = next) {
        next = (*sound_manager)->next;
        delete_sound(sound_manager, *sound_manager);
    }
}

static void free_game_clocks(clocks_t *clocks)
{
    if (clocks == NULL)
        return;
    if (clocks->fps != NULL)
        sfClock_destroy(clocks->fps);
    if (clocks->player_anim != NULL)
        sfClock_destroy(clocks->player_anim);
    if (clocks->player_dash != NULL)
        sfClock_destroy(clocks->player_dash);
    if (clocks->player_dash_smoke != NULL)
        sfClock_destroy(clocks->player_dash_smoke);
    free(clocks);
}

static void free_player(player_t *player)
{
    sfView_destroy(player->cam);
    sfSprite_destroy(player->sprite);
    free_hitbox(player->dep_hitbox);
    free_weapon(player->wp1);
    free_weapon(player->wp2);
    free(player);
}

static void free_ui(game_t *game)
{
    if (game->ui->heart != NULL)
        heart_destroy(game->ui->heart);
    if (game->ui->shop != NULL) {
        shop_destroy(game->ui->shop);
        game->ui->shop = NULL;
    }
    if (game->ui->artefact != NULL) {
        free_artefact_struct(game->ui->artefact);
        game->ui->artefact = NULL;
    }
}

void free_game_not_res_or_window(game_t *game)
{
    if (game->anims != NULL)
        free_anim_list(&(game->anims));
    free_game_clocks(game->clocks);
    if (game->sound_manager != NULL)
        free_sound_manager(&(game->sound_manager));
    if (game->player != NULL)
        free_player(game->player);
    if (game->map != NULL)
        free_current_map(game);
    free_system(game);
    if (game->ui != NULL)
        free_ui(game);
    game->map = NULL;
    game->player = NULL;
    game->anims = NULL;
    game->sound_manager = NULL;
    game->ui = NULL;
    game->system = NULL;
    game->dialogue = NULL;
    game->clocks = NULL;
}
