/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** act_dialogue
*/

#include "game.h"
#include "dialogue.h"
#include <stdio.h>

int act_dialogue(game_t *game)
{
    dialogue_t *d = game->dialogue;
    sfTime time = sfClock_getElapsedTime(d->clock);
    float delta = time.microseconds / 1000000.0;

    if (d->state == DIALOGUE_WAIT) {
        if (delta < d->wait_time)
            return 1;
        d->state = DIALOGUE_PLAY;
    }
    if (d->state == DIALOGUE_PLAY) {
        if (delta * 17.6 > 1) {
            advance_dialogue(game);
            sfClock_restart(d->clock);
        }
    }
    if (d->state == DIALOGUE_END) {
        delete_dialogue(&(game->dialogue), d);
        return 0;
    }
    return 1;
}
