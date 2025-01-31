/*
** EPITECH PROJECT, 2024
** main_menu.c
** File description:
** main menu functions
*/

#include "game.h"
#include "menu.h"
#include <math.h>
#include "SFML/Graphics.h"
#include "inventory.h"
#include <stdio.h>

static const int pos_play = 200;
static const int pos_option = 500;
static const int pos_exit = 800;

static float calculate_speed_anim(sfSprite *sprite, int pos_final)
{
    return sqrt(pos_final - sfSprite_getPosition(sprite).y) / 20 + 1000;
}

static float find_sprite_to_anim(menu_t *menu, sfSprite **sprite)
{
    double s;

    if (sfSprite_getPosition(menu->exit_button).y < pos_exit) {
        *sprite = menu->exit_button;
        s = calculate_speed_anim(menu->exit_button, pos_exit);
        return s * sfTime_asMilliseconds(sfClock_getElapsedTime(menu->clock));
    }
    if (sfSprite_getPosition(menu->option_button).y < pos_option) {
        *sprite = menu->option_button;
        s = calculate_speed_anim(menu->option_button, pos_option);
        return s * sfTime_asMilliseconds(sfClock_getElapsedTime(menu->clock));
    }
    if (sfSprite_getPosition(menu->play_button).y < pos_play) {
        *sprite = menu->play_button;
        s = calculate_speed_anim(menu->play_button, pos_play);
        return s * sfTime_asMilliseconds(sfClock_getElapsedTime(menu->clock));
    }
    return 0;
}

void handle_animation(game_t *game)
{
    sfSprite *sprite = NULL;
    float speed = find_sprite_to_anim(game->menu, &sprite);
    sfVector2f pos;

    if (sprite == NULL) {
        game->menu->in_animation = 0;
        return;
    }
    pos = (sfVector2f){750, sfSprite_getPosition(sprite).y + speed};
    sfClock_restart(game->menu->clock);
    if (sprite == game->menu->exit_button && pos.y > pos_exit)
        pos.y = pos_exit;
    if (sprite == game->menu->option_button && pos.y > pos_option)
        pos.y = pos_option;
    if (sprite == game->menu->play_button && pos.y > pos_play)
        pos.y = pos_play;
    sfSprite_setPosition(sprite, pos);
}

static void handle_menu2(game_t *game)
{
    char buf[256];

    if (game->menu->statut == MENU && game->menu->f_flag)
        sfRenderWindow_drawSprite(game->window, game->menu->quit_button, NULL);
    if (game->menu->statut == OPTION) {
        sfRenderWindow_drawSprite(game->window, game->menu->bg, NULL);
        sfRenderWindow_drawSprite(game->window, game->menu->res1_button, NULL);
        sfRenderWindow_drawSprite(game->window, game->menu->res2_button, NULL);
        sfRenderWindow_drawSprite(game->window, game->menu->res3_button, NULL);
        sfSprite_setPosition(game->menu->home_button, (sfVector2f){744, 900});
        sfRenderWindow_drawSprite(game->window, game->menu->home_button, NULL);
    }
    if (game->menu->statut == INFO) {
        sprintf(buf, "In Game Time : %d seconds", load());
        sfText_setString(game->menu->in_game_time, buf);
        sfRenderWindow_drawSprite(game->window, game->menu->htp, NULL);
        sfSprite_setPosition(game->menu->home_button, (sfVector2f){800, 750});
        sfRenderWindow_drawSprite(game->window, game->menu->home_button, NULL);
        sfRenderWindow_drawText(game->window, game->menu->in_game_time, NULL);
    }
}

void init_button_states(game_t *game)
{
    sfIntRect rect;
    sfFloatRect hitbox;
    sfBool clicked = sfMouse_isButtonPressed(sfMouseLeft);
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->window);
    sfSprite *sprites[4] = {game->menu->home_button, game->menu->option_button,
        game->menu->exit_button, game->menu->play_button};

    pos.x = pos.x / game->menu->window_size.x * 1920;
    pos.y = pos.y / game->menu->window_size.y * 1080;
    for (int i = 0; i < 4; i++) {
        rect = (sfIntRect) {0, 0, 790, 343};
        hitbox = sfSprite_getGlobalBounds(sprites[i]);
        if (sfFloatRect_contains(&hitbox, pos.x, pos.y) && clicked)
            rect.left = 1580;
        if (sfFloatRect_contains(&hitbox, pos.x, pos.y) && !clicked)
            rect.left = 790;
        sfSprite_setTextureRect(sprites[i], rect);
    }
}

void handle_menu(game_t *game)
{
    init_button_states(game);
    if ((game->menu->in_animation == 2 && sfTime_asSeconds
        (sfClock_getElapsedTime(game->menu->clock)) > 1) ||
        game->menu->in_animation == 1) {
        if (game->menu->in_animation == 2)
            sfClock_restart(game->menu->clock);
        game->menu->in_animation = 1;
        handle_animation(game);
    }
    sfRenderWindow_clear(game->window, sfBlack);
    if (game->menu->statut == MENU) {
        sfRenderWindow_drawSprite(game->window, game->menu->bg, NULL);
        sfRenderWindow_drawSprite(game->window, game->menu->play_button, NULL);
        sfRenderWindow_drawSprite
            (game->window, game->menu->option_button, NULL);
        sfRenderWindow_drawSprite(game->window, game->menu->exit_button, NULL);
    }
    handle_menu2(game);
    sfRenderWindow_display(game->window);
}
