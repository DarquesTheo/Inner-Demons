/*
** EPITECH PROJECT, 2024
** init_artefact.c
** File description:
** init artefact
*/

#include "res.h"
#include "artefact.h"
#include "utils.h"
#include "game.h"
#include "vector.h"
#include <stdlib.h>
#include <string.h>

static const char *stat_str_ref[10] = {"Damage [", "Attack Speed [",
    "Movement Speed [", "Accuracy [", "Luck [", "Intelligence [", "Dodge [",
    "Lifesteal [", "Double Shot [", "Critical Hit ["};
static const int quality_max_ref[10] = {10, 12, 10, 10, 8, 8, 3, 1, 5, 5};
static const int quality_min_ref[10] = {0, 0, 0, 10, 2, 2, 0, 0, 0, 0};
static const float quality_incr_ref[10] =
{5, 4, 3, 10, 3, 3, 1.5, 0.25, 3.5, 3};
static const int quality_cap_ref[10] =
{120, 120, 120, 300, 80, 80, 40, 10, 100, 100};

static void add_stat_line3(ui_line_artefact_t *new)
{
    sfSprite_setScale(new->roll_quality, v2f(0.22, 0.22));
    sfSprite_setScale(new->roll_stat, v2f(0.22, 0.22));
    sfSprite_setScale(new->unlock, v2f(0.22, 0.22));
    sfSprite_setTextureRect(new->roll_quality, (sfIntRect) {0, 0, 790, 343});
    sfSprite_setTextureRect(new->unlock, (sfIntRect) {0, 0, 790, 343});
    sfSprite_setTextureRect(new->roll_stat, (sfIntRect) {0, 0, 790, 343});
    if (new->type == DODGE)
        sfText_setString(new->text_stat, "Dodge");
    if (new->type == LIFESTEAL)
        sfText_setString(new->text_stat, "Lifesteal");
    if (new->type == DOUBLE_SHOT)
        sfText_setString(new->text_stat, "Double shot");
    if (new->type == COUP_CRITIQUE)
        sfText_setString(new->text_stat, "Critical Hit");
    if (new->type == COUP_CRITIQUE || new->type == LIFESTEAL ||
        new->type == DOUBLE_SHOT || new->type == DODGE)
        sfText_setString(new->text_percent, "0%");
}

static void add_stat_line2(ui_line_artefact_t *new, res_artefact_t *res)
{
    new->roll_quality = sfSprite_create();
    new->roll_stat = sfSprite_create();
    new->unlock = sfSprite_create();
    sfSprite_setTexture(new->roll_quality, res->roll_quality, sfFalse);
    sfSprite_setTexture(new->roll_stat, res->roll_stat, sfFalse);
    sfSprite_setTexture(new->unlock, res->unlock, sfFalse);
    add_stat_line3(new);
}

void place_lines(ui_line_artefact_t *list)
{
    int i = 0;
    sfVector2f offset;

    for (ui_line_artefact_t *node = list; node != NULL; node = node->next)
        i++;
    for (ui_line_artefact_t *node = list; node != NULL; node = node->next) {
        offset = (sfVector2f)
            {100000 - 400, 100000 - 40 * i + 80 * node->index};
        sfText_setPosition(node->text_stat, add_vectors(offset, v2f(0, 25)));
        sfSprite_setPosition(node->unlock, offset);
        offset.x += 500;
        sfText_setPosition(node->text_percent,
            add_vectors(offset, v2f(0, 25)));
        offset.x += 200;
        sfSprite_setPosition(node->roll_quality, offset);
        offset.x += 300;
        sfSprite_setPosition(node->roll_stat, offset);
    }
}

void add_stat_line(ui_line_artefact_t **list, stat_type_t type, res_t *res)
{
    ui_line_artefact_t *new = malloc(sizeof(ui_line_artefact_t));

    if (*list == NULL)
        new->index = 0;
    else
        new->index = (*list)->index + 1;
    new->type = type;
    if (type == 42)
        new->unlocked = sfFalse;
    else
        new->unlocked = sfTrue;
    new->quality = 0;
    new->text_stat = sfText_create();
    new->text_percent = sfText_create();
    sfText_setFont(new->text_stat, res->fonts->dialogue_font);
    sfText_setFont(new->text_percent, res->fonts->dialogue_font);
    add_stat_line2(new, res->artefact);
    new->next = *list;
    *list = new;
}

static void init_artefact_struct2(res_t *res, artefact_t *new)
{
    sfSprite_setTexture(new->sprite, res->artefact->artefact, sfFalse);
    sfSprite_setTexture(new->bg, res->artefact->bg, sfFalse);
    sfSprite_setTexture(new->back, res->artefact->back, sfFalse);
    sfSprite_setPosition(new->back, v2f(100000 - 1940 / 2, 100000 + 940 / 2));
    sfSprite_setPosition(new->bg, v2f(100000 - 1920 / 2, 100000 - 1080 / 2));
    sfSprite_setPosition(new->sprite, v2f(100000 - 1820 / 2, 100000 - 400));
    sfSprite_setScale(new->back, v2f(0.25, 0.25));
    sfSprite_setScale(new->sprite, v2f(3, 3));
    sfSprite_setScale(new->bg, v2f(2.5, 2.05));
    new->range = malloc(sizeof(range_artefact_t));
    for (int i = 0; i < 10; i++) {
        new->range->quality_incr[i] = quality_incr_ref[i];
        new->range->quality_cap[i] = quality_cap_ref[i];
        new->range->quality_max[i] = quality_max_ref[i];
        new->range->quality_min[i] = quality_min_ref[i];
        new->range->stat_str[i] = strdup(stat_str_ref[i]);
        new->range->text[i] = sfText_create();
        sfText_setCharacterSize(new->range->text[i], 20);
        sfText_setFont(new->range->text[i], res->fonts->dialogue_font);
    }
}

static void init_artefact_struct3(res_t *res, artefact_t *new)
{
    new->max_exp = 1000;
    new->cur_exp = 0;
    new->exp_bar = sfRectangleShape_create();
    new->exp_bar_sprite = sfSprite_create();
    sfSprite_setTexture(new->exp_bar_sprite, res->artefact->exp_bar, sfFalse);
    sfSprite_setPosition(new->exp_bar_sprite, v2f(100000 - 320 / 2,
        100000 + 900 / 2));
    sfSprite_setScale(new->exp_bar_sprite, v2f(5, 5));
    sfRectangleShape_setSize(new->exp_bar, v2f(300, 30));
    sfRectangleShape_setPosition(new->exp_bar, v2f(100000 - 300 / 2,
        100000 + 920 / 2));
    sfRectangleShape_setFillColor(new->exp_bar, sfColor_fromRGB(0, 0, 255));
    sfSprite_setTextureRect(new->sprite, new->rect);
    new->text_roll_price = sfText_create();
    sfText_setPosition(new->text_roll_price,
        v2f(100000 - 1820 / 2, 100000 - 1000 / 2));
    sfText_setFont(new->text_roll_price, res->fonts->dialogue_font);
    sfText_setCharacterSize(new->text_roll_price, 28);
}

artefact_t *init_artefact_struct(res_t *res)
{
    artefact_t *new = malloc(sizeof(artefact_t));

    new->lines = NULL;
    new->clock = sfClock_create();
    new->visible = sfFalse;
    new->level = 1;
    new->rect = (sfIntRect) {0, 0, 150, 150};
    new->sprite = sfSprite_create();
    new->bg = sfSprite_create();
    new->back = sfSprite_create();
    new->stat_table = sfSprite_create();
    sfSprite_setTexture(new->stat_table, res->artefact->stat_table, sfFalse);
    sfSprite_setPosition(new->stat_table, v2f(100000 - 1900 / 2, 100000 - 10));
    sfSprite_setScale(new->stat_table, v2f(11.5, 11));
    new->on_click = sfFalse;
    init_artefact_struct2(res, new);
    init_artefact_struct3(res, new);
    new->text_level = sfText_create();
    sfText_setFont(new->text_level, res->fonts->dialogue_font);
    return new;
}

res_artefact_t *init_res_artefact(void)
{
    res_artefact_t *new = malloc(sizeof(res_artefact_t));

    new->bg = sfTexture_createFromFile("res/inventory/artefact/bg.png", NULL);
    new->artefact =
        sfTexture_createFromFile("res/inventory/artefact/arte.png", NULL);
    new->unlock =
        sfTexture_createFromFile("res/inventory/artefact/unlock.png", NULL);
    new->roll_stat =
        sfTexture_createFromFile("res/inventory/artefact/roll_stat.png", NULL);
    new->back =
        sfTexture_createFromFile("res/inventory/artefact/back.png", NULL);
    new->stat_table =
        sfTexture_createFromFile("res/inventory/artefact/stat.png", NULL);
    new->roll_quality = sfTexture_createFromFile
        ("res/inventory/artefact/roll_quality.png", NULL);
    new->exp_bar = sfTexture_createFromFile
        ("res/inventory/artefact/exp_bar.png", NULL);
    new->hp_bar = sfTexture_createFromFile
        ("res/inventory/artefact/boss_hb_big.png", NULL);
    return new;
}
