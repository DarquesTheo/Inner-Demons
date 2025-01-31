/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** on_each_fps_player
*/

#include "game.h"
#include "utils.h"
#include "vector.h"
#include "player.h"
#include "map.h"
#include "ui.h"

static void move_player_objects(game_t *game, sfVector2f player_pos)
{
    if (game->player->wp1 != NULL)
        sfSprite_setPosition(game->player->wp1->sprite,
        add_vectors(player_pos, (sfVector2f){-30, 0}));
    if (game->player->wp2 != NULL)
        sfSprite_setPosition(game->player->wp2->sprite,
        add_vectors(player_pos, (sfVector2f){30, 0}));
    sfView_setCenter(game->player->cam, player_pos);
    sfRenderWindow_setView(game->window, game->player->cam);
}

static void player_draw_left(game_t *game)
{
    if (game->player->wp1)
        sfRenderWindow_drawSprite(game->window, game->player->wp1->sprite, 0);
    sfRenderWindow_drawSprite(game->window, game->player->sprite, NULL);
    if (game->player->wp2)
        sfRenderWindow_drawSprite(game->window, game->player->wp2->sprite, 0);
}

static void player_draw_right(game_t *game)
{
    if (game->player->wp2)
        sfRenderWindow_drawSprite(game->window, game->player->wp2->sprite, 0);
    sfRenderWindow_drawSprite(game->window, game->player->sprite, NULL);
    if (game->player->wp1)
        sfRenderWindow_drawSprite(game->window, game->player->wp1->sprite, 0);
}

static void player_draw_top(game_t *game)
{
    if (game->player->wp1)
        sfRenderWindow_drawSprite(game->window, game->player->wp1->sprite, 0);
    if (game->player->wp2)
        sfRenderWindow_drawSprite(game->window, game->player->wp2->sprite, 0);
    sfRenderWindow_drawSprite(game->window, game->player->sprite, NULL);
}

static void player_draw_bottom(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->player->sprite, NULL);
    if (game->player->wp1)
        sfRenderWindow_drawSprite(game->window, game->player->wp1->sprite, 0);
    if (game->player->wp2)
        sfRenderWindow_drawSprite(game->window, game->player->wp2->sprite, 0);
}

static void player_draw2(game_t *game)
{
    if (game->info->debug) {
        sfRenderWindow_drawRectangleShape(game->window,
        game->player->dep_hitbox->rect, NULL);
        sfRenderWindow_drawRectangleShape(game->window,
        game->player->hitbox->rect, NULL);
    }
}

static void player_draw(game_t *game)
{
    if (game->player->state == DASHING) {
        sfRenderWindow_drawSprite(game->window, game->player->sprite, NULL);
        return;
    }
    switch (game->info->mouse_side) {
        case LEFT:
            player_draw_left(game);
            break;
        case RIGHT :
            player_draw_right(game);
            break;
        case TOP:
            player_draw_top(game);
            break;
        case BOTTOM:
            player_draw_bottom(game);
    }
    player_draw2(game);
}

static void act_player_invincibility(player_t *p)
{
    sfTime time = sfClock_getElapsedTime(p->states->invincibility);
    float delta = sfTime_asSeconds(time);

    if (delta * INVINCIBILITY_TIME > 1) {
        p->states->can_take_dmg = sfTrue;
        sfSprite_setColor(p->sprite, sfWhite);
        if (p->wp1)
            sfSprite_setColor(p->wp1->sprite, sfWhite);
        if (p->wp2)
            sfSprite_setColor(p->wp2->sprite, sfWhite);
    }
}

void on_each_fps_player(game_t *game, float delta)
{
    sfVector2f player_pos = sfSprite_getPosition(game->player->sprite);

    if (game->player->states->can_take_dmg == sfFalse
    && game->ui->death_menu->active == sfFalse)
        act_player_invincibility(game->player);
    move_player(game, delta);
    move_player_objects(game, player_pos);
    player_shoot(game);
    player_draw(game);
}
