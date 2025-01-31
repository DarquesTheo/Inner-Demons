/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** act_dialogue
*/

#include <string.h>
#include "utils.h"
#include "game.h"
#include "dialogue.h"
#include <stdlib.h>
#include "res.h"
#include "map.h"
#include <stdio.h>

static sfRectangleShape *get_dialogue_rect(void)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfVector2f size = {1400, 300};
    int offset_from_bottom = 30;

    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setPosition(rect,
    v2f(100000 - size.x / 2, (100000 + 540 - size.y) - offset_from_bottom));
    sfRectangleShape_setFillColor(rect, (sfColor){0, 0, 0, 255});
    sfRectangleShape_setOutlineColor(rect, (sfColor){255, 255, 255, 255});
    sfRectangleShape_setOutlineThickness(rect, 15);
    return rect;
}

static sfText *get_dialogue_text(char *str, sfFont *font,
    sfRectangleShape *rect)
{
    sfText *text = sfText_create();
    sfVector2f rect_pos = sfRectangleShape_getPosition(rect);

    sfText_setString(text, str);
    sfText_setCharacterSize(text, 30);
    sfText_setFont(text, font);
    sfText_setPosition(text, v2f(rect_pos.x + 25, rect_pos.y + 25));
    sfText_setColor(text, (sfColor){255, 255, 255, 255});
    return text;
}

static dialogue_t *get_default_dialogue(char *str, sfFont *font)
{
    dialogue_t *dialogue = malloc(sizeof(dialogue_t));

    dialogue->clock = sfClock_create();
    dialogue->sprite = sfSprite_create();
    dialogue->str = strdup(str);
    dialogue->cur_str = strdup(str);
    dialogue->cur_str[0] = 0;
    dialogue->hint = 0;
    dialogue->size = strlen(str);
    dialogue->rect = get_dialogue_rect();
    dialogue->text = get_dialogue_text(0, font, dialogue->rect);
    dialogue->wait_time = 2;
    dialogue->state = DIALOGUE_WAIT;
    return dialogue;
}

//enter file name only, the file have to be in res/dialogues/
void add_dialogue(game_t *game, char *name)
{
    dialogue_t *new;
    char path[1000] = {0};
    char *str;

    strcat(path, "res/dialogues/");
    strcat(path, name);
    str = get_file_content(path);
    if (!str) {
        printf("wrong dialogue path\n");
        return;
    }
    new = get_default_dialogue(str, game->res->fonts->dialogue_font);
    new->prev = NULL;
    new->next = game->dialogue;
    if (game->dialogue != NULL)
        game->dialogue->prev = new;
    game->dialogue = new;
    free(str);
}
