/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** skip_dialogue
*/

#include "game.h"
#include "dialogue.h"

void skip_dialogue(game_t *game)
{
    dialogue_t *d = game->dialogue;
    dialogue_state_t state = d->state;

    if (state == DIALOGUE_WAIT)
        d->state = DIALOGUE_PLAY;
    if (state == DIALOGUE_PLAY) {
        d->hint = d->size - 1;
        act_dialogue(game);
    }
    if (state == DIALOGUE_COMPLETE) {
        d->state = DIALOGUE_END;
    }
}
