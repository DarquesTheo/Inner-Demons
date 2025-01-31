/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-baptiste.camerlynck
** File description:
** init_menu
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "game.h"
#include "menu.h"
#include "game_menu.h"
#include "utils.h"
#include "res.h"
#include <stdlib.h>

static menu_t *init_menu4(menu_t *new, game_t *game)
{
    new->in_game_time = sfText_create();
    sfText_setPosition(new->in_game_time, v2f(0, 0));
    sfText_setColor(new->in_game_time, sfBlack);
    sfText_setFont(new->in_game_time, game->res->fonts->dialogue_font);
    return new;
}

static menu_t *init_menu3(menu_t *new, game_t *game)
{
    sfTexture *htp_tex = sfTexture_createFromFile("res/menu/htp.png", NULL);
    sfTexture *quit_tex = sfTexture_createFromFile("res/menu/exit.png", NULL);

    new->htp = sfSprite_create();
    new->quit_button = sfSprite_create();
    sfSprite_setTexture(new->htp, htp_tex, sfTrue);
    sfSprite_setTexture(new->quit_button, quit_tex, sfTrue);
    sfSprite_scale(new->quit_button, (sfVector2f) {3, 3});
    sfSprite_setPosition(new->quit_button, (sfVector2f) {1824, 0});
    sfSprite_scale(new->play_button, (sfVector2f) {0.5, 0.5});
    sfSprite_scale(new->exit_button, (sfVector2f) {0.5, 0.5});
    sfSprite_scale(new->option_button, (sfVector2f) {0.5, 0.5});
    sfSprite_scale(new->home_button, (sfVector2f) {0.5, 0.5});
    sfSprite_scale(new->res1_button, (sfVector2f) {0.5, 0.5});
    sfSprite_scale(new->res2_button, (sfVector2f) {0.5, 0.5});
    sfSprite_scale(new->res3_button, (sfVector2f) {0.5, 0.5});
    new->music = sfMusic_createFromFile("res/music/main_menu.ogg");
    sfMusic_setLoop(new->music, sfTrue);
    sfMusic_play(new->music);
    return init_menu4(new, game);
}

static menu_t *init_menu2(menu_t *new, game_t *game)
{
    sfTexture *home_tex = sfTexture_createFromFile("res/menu/home.png", NULL);
    sfTexture *res1_tex = sfTexture_createFromFile("res/menu/res1.png", NULL);
    sfTexture *res2_tex = sfTexture_createFromFile("res/menu/res2.png", NULL);
    sfTexture *res3_tex = sfTexture_createFromFile("res/menu/res3.png", NULL);

    new->home_button = sfSprite_create();
    new->res1_button = sfSprite_create();
    new->res2_button = sfSprite_create();
    new->res3_button = sfSprite_create();
    sfSprite_setTexture(new->home_button, home_tex, sfTrue);
    sfSprite_setTexture(new->res1_button, res1_tex, sfTrue);
    sfSprite_setTexture(new->res2_button, res2_tex, sfTrue);
    sfSprite_setTexture(new->res3_button, res3_tex, sfTrue);
    sfSprite_setPosition(new->res1_button, (sfVector2f){750, 50});
    sfSprite_setPosition(new->res2_button, (sfVector2f){750, 250});
    sfSprite_setPosition(new->res3_button, (sfVector2f){750, 450});
    sfSprite_setPosition(new->home_button, (sfVector2f){750, 900});
    new->statut = MENU;
    new->window_size = (sfVector2f) {1920, 1080};
    return init_menu3(new, game);
}

menu_t *init_menu(game_t *game)
{
    menu_t *new = malloc(sizeof(menu_t));
    sfTexture *play_tex = sfTexture_createFromFile("res/menu/play.png", NULL);
    sfTexture *opt_tex = sfTexture_createFromFile("res/menu/option.png", NULL);
    sfTexture *exit_tex = sfTexture_createFromFile("res/menu/info.png", NULL);
    sfTexture *bg_tex = sfTexture_createFromFile("res/menu/bg.png", NULL);

    new->clock = sfClock_create();
    new->in_animation = 2;
    new->bg = sfSprite_create();
    new->play_button = sfSprite_create();
    new->option_button = sfSprite_create();
    new->exit_button = sfSprite_create();
    sfSprite_setTexture(new->bg, bg_tex, sfTrue);
    sfSprite_setTexture(new->play_button, play_tex, sfTrue);
    sfSprite_setTexture(new->option_button, opt_tex, sfTrue);
    sfSprite_setTexture(new->exit_button, exit_tex, sfTrue);
    sfSprite_setPosition(new->play_button, (sfVector2f){0, -170});
    sfSprite_setPosition(new->option_button, (sfVector2f){0, -170});
    sfSprite_setPosition(new->exit_button, (sfVector2f){0, -170});
    return init_menu2(new, game);
}

static game_menu_t *init_game_menu3(game_menu_t *new)
{
    sfTexture *res1_tex = sfTexture_createFromFile("res/menu/res1.png", NULL);
    sfTexture *res2_tex = sfTexture_createFromFile("res/menu/res2.png", NULL);
    sfTexture *res3_tex = sfTexture_createFromFile("res/menu/res3.png", NULL);

    new->res1_button = sfSprite_create();
    new->res2_button = sfSprite_create();
    new->res3_button = sfSprite_create();
    sfSprite_setTexture(new->res1_button, res1_tex, sfTrue);
    sfSprite_setTexture(new->res2_button, res2_tex, sfTrue);
    sfSprite_setTexture(new->res3_button, res3_tex, sfTrue);
    sfSprite_setPosition(new->res1_button, (sfVector2f){99500, 99600});
    sfSprite_setPosition(new->res2_button, (sfVector2f){99500, 99750});
    sfSprite_setPosition(new->res3_button, (sfVector2f){99500, 99900});
    sfSprite_scale(new->res1_button, (sfVector2f) {0.35, 0.35});
    sfSprite_scale(new->res2_button, (sfVector2f) {0.35, 0.35});
    sfSprite_scale(new->res3_button, (sfVector2f) {0.35, 0.35});
    return new;
}

static game_menu_t *init_menu_slider(game_menu_t *new)
{
    sfFont *font = sfFont_createFromFile("res/inventory/inventory_font.ttf");

    new->sfx_text = sfText_create();
    new->music_text = sfText_create();
    new->sfx_percent = sfText_create();
    new->music_percent = sfText_create();
    sfText_setFont(new->sfx_text, font);
    sfText_setFont(new->music_text, font);
    sfText_setFont(new->music_percent, font);
    sfText_setFont(new->sfx_percent, font);
    sfText_setString(new->sfx_text, "SFX Volume");
    sfText_setString(new->music_text, "Music Volume");
    sfText_setPosition(new->sfx_text, (sfVector2f){100100, 99600});
    sfText_setPosition(new->music_text, (sfVector2f){100100, 99750});
    slider_setposition(new->sfx_slider, (sfVector2f){100100, 99650});
    slider_setposition(new->music_slider, (sfVector2f){100100, 99800});
    slider_updatevalue(new->music_slider, 1);
    slider_updatevalue(new->sfx_slider, 1);
    return new;
}

static game_menu_t *init_game_menu2(game_menu_t *new)
{
    new->shade = sfRectangleShape_create();
    sfRectangleShape_setSize(new->shade, (sfVector2f) {1920, 1080});
    sfRectangleShape_setPosition
        (new->shade, (sfVector2f) {100000 - 960, 100000 - 540});
    sfRectangleShape_setFillColor(new->shade, sfColor_fromRGBA(0, 0, 0, 150));
    new->music_slider = slider_create_default();
    new->sfx_slider = slider_create_default();
    new = init_menu_slider(new);
    sfText_setPosition(new->sfx_percent, (sfVector2f){100520, 99650});
    sfText_setPosition(new->music_percent, (sfVector2f){100520, 99800});
    sfText_setString(new->sfx_percent, "100%");
    sfText_setString(new->music_percent, "100%");
    return init_game_menu3(new);
}

game_menu_t *init_game_menu(void)
{
    game_menu_t *new = malloc(sizeof(game_menu_t));
    sfTexture *resume_tex =
        sfTexture_createFromFile("res/menu2/resume.png", NULL);
    sfTexture *home_tex = sfTexture_createFromFile("res/menu/home.png", NULL);
    sfTexture *bg_tex = sfTexture_createFromFile("res/menu2/bg.png", NULL);

    new->bg = sfSprite_create();
    new->home_button = sfSprite_create();
    new->resume_button = sfSprite_create();
    sfSprite_setTexture(new->bg, bg_tex, sfTrue);
    sfSprite_setTexture(new->resume_button, resume_tex, sfTrue);
    sfSprite_setTexture(new->home_button, home_tex, sfTrue);
    sfSprite_setPosition(new->home_button, (sfVector2f){99590, 100260});
    sfSprite_setPosition(new->resume_button, (sfVector2f){100220, 100260});
    sfSprite_setPosition(new->bg, (sfVector2f){-670 + 100000, -500 + 100000});
    sfSprite_scale(new->home_button, (sfVector2f) {0.35, 0.35});
    sfSprite_scale(new->resume_button, (sfVector2f) {0.35, 0.35});
    sfSprite_scale(new->bg, (sfVector2f) {1.8, 1.8});
    return init_game_menu2(new);
}
