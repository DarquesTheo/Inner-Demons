/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** act_dialogue
*/

#include "game.h"
#include "dialogue.h"
#include "sound_manager.h"
#include "utils.h"

void advance_dialogue(game_t *game)
{
    dialogue_t *d = game->dialogue;

    d->cur_str[d->hint] = d->str[d->hint];
    if (d->str[d->hint] != ' ')
        play_sound(game, "tick", rand_float(0.5, 1.5));
    d->cur_str[d->hint + 1] = 0;
    sfText_setString(d->text, d->cur_str);
    d->hint += 1;
    if (d->hint == d->size) {
        sfText_setString(d->text, d->str);
        d->state = DIALOGUE_COMPLETE;
    }
}
