/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** draw_dialogue
*/

#include "game.h"
#include "dialogue.h"

void draw_dialogue(game_t *game)
{
    if (game->dialogue != NULL) {
        if (act_dialogue(game) == 1) {
            sfRenderWindow_drawRectangleShape(game->window,
            game->dialogue->rect, NULL);
            sfRenderWindow_drawText(game->window, game->dialogue->text, NULL);
        }
    }
}
