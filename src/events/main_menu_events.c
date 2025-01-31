/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-baptiste.camerlynck
** File description:
** main_menu_events
*/

#include "game.h"
#include "player.h"
#include "menu.h"

static sfVector2f calculate_mouse_pos(sfVector2f pos, game_t *game)
{
    return (sfVector2f) {pos.x / game->menu->window_size.x * 1920,
        pos.y / game->menu->window_size.y * 1080};
}

static void mouse_pressed_in_menu2(game_t *game, sfEvent event)
{
    sfVector2f pos = (sfVector2f) {event.mouseButton.x, event.mouseButton.y};
    sfFloatRect quit_rect = sfSprite_getGlobalBounds(game->menu->quit_button);

    pos = calculate_mouse_pos(pos, game);
    if (sfFloatRect_contains(&quit_rect, pos.x, pos.y) && game->menu->f_flag)
        sfRenderWindow_close(game->window);
}

static void mouse_pressed_in_menu(game_t *game, sfEvent event)
{
    sfVector2f pos = (sfVector2f) {event.mouseButton.x, event.mouseButton.y};
    sfFloatRect play_rect = sfSprite_getGlobalBounds(game->menu->play_button);
    sfFloatRect option_rect =
        sfSprite_getGlobalBounds(game->menu->option_button);
    sfFloatRect info_rect = sfSprite_getGlobalBounds(game->menu->exit_button);

    pos = calculate_mouse_pos(pos, game);
    if (event.mouseButton.button != sfMouseLeft)
        return;
    if (sfFloatRect_contains(&play_rect, pos.x, pos.y)) {
        sfMusic_destroy(game->menu->music);
        game->menu->music = NULL;
        start_game(game);
    }
    if (sfFloatRect_contains(&option_rect, pos.x, pos.y))
        game->menu->statut = OPTION;
    if (sfFloatRect_contains(&info_rect, pos.x, pos.y))
        game->menu->statut = INFO;
    mouse_pressed_in_menu2(game, event);
}

void change_resolution(game_t *game, int x, int y)
{
    sfVideoMode video_mode = (sfVideoMode) {x, y, 32};

    game->menu->window_size = (sfVector2f) {x, y};
    sfRenderWindow_destroy(game->window);
    game->window = sfRenderWindow_create(video_mode,
        "my_rpg", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(game->window, 360);
    sfRenderWindow_setKeyRepeatEnabled(game->window, sfFalse);
    sfRenderWindow_setView(game->window,
        sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080}));
}

static void mouse_pressed_in_option(game_t *game, sfEvent event)
{
    sfVector2f pos = (sfVector2f) {event.mouseButton.x, event.mouseButton.y};
    sfFloatRect res1_rect = sfSprite_getGlobalBounds(game->menu->res1_button);
    sfFloatRect res2_rect = sfSprite_getGlobalBounds(game->menu->res2_button);
    sfFloatRect res3_rect = sfSprite_getGlobalBounds(game->menu->res3_button);
    sfFloatRect home_rect = sfSprite_getGlobalBounds(game->menu->home_button);

    pos = calculate_mouse_pos(pos, game);
    if (event.mouseButton.button != sfMouseLeft)
        return;
    if (sfFloatRect_contains(&home_rect, pos.x, pos.y))
        game->menu->statut = MENU;
    if (game->menu->f_flag)
        return;
    if (sfFloatRect_contains(&res1_rect, pos.x, pos.y))
        change_resolution(game, 1920, 1080);
    if (sfFloatRect_contains(&res2_rect, pos.x, pos.y))
        change_resolution(game, 1600, 900);
    if (sfFloatRect_contains(&res3_rect, pos.x, pos.y))
        change_resolution(game, 800, 450);
}

static void mouse_pressed_in_info(game_t *game, sfEvent event)
{
    sfVector2f pos = (sfVector2f) {event.mouseButton.x, event.mouseButton.y};
    sfFloatRect home_rect = sfSprite_getGlobalBounds(game->menu->home_button);

    pos = calculate_mouse_pos(pos, game);
    if (event.mouseButton.button != sfMouseLeft)
        return;
    if (sfFloatRect_contains(&home_rect, pos.x, pos.y))
        game->menu->statut = MENU;
}

static void resize_in_menu(game_t *game, sfEvent event)
{
    game->menu->window_size =
        (sfVector2f) {event.size.width, event.size.height};
}

static void key_pressed_in_menu(game_t *game, sfEvent event)
{
    if (event.key.code == sfKeyEscape) {
        if (game->menu->statut == MENU)
            sfRenderWindow_close(game->window);
        if (game->menu->statut != MENU)
            game->menu->statut = MENU;
    }
}

static void mouse_pressed_in(game_t *game, sfEvent event)
{
    switch (game->menu->statut) {
    case MENU:
        mouse_pressed_in_menu(game, event);
        break;
    case OPTION:
        mouse_pressed_in_option(game, event);
        break;
    case INFO:
        mouse_pressed_in_info(game, event);
        break;
    default:
        break;
    }
}

void process_mmenu_events(game_t *game, sfEvent event)
{
    if (game->menu->music == NULL) {
        game->menu->music = sfMusic_createFromFile("res/music/main_menu.ogg");
        sfMusic_setLoop(game->menu->music, sfTrue);
        sfMusic_play(game->menu->music);
    }
    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (event.type == sfEvtKeyPressed)
            key_pressed_in_menu(game, event);
        if (event.type == sfEvtMouseButtonReleased &&
            game->menu->in_animation == 0) {
            mouse_pressed_in(game, event);
        }
        if (event.type == sfEvtResized)
            resize_in_menu(game, event);
    }
}
