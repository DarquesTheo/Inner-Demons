/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** add_sound
*/

#include "game.h"
#include "sound_manager.h"
#include "res.h"
#include <stdlib.h>
#include <stdio.h>

static void add_sound_to_list(game_t *game, sfSound *sound)
{
    sound_manager_t *new = malloc(sizeof(sound_manager_t));

    new->sound = sound;
    new->prev = NULL;
    new->next = game->sound_manager;
    if (game->sound_manager != NULL)
        game->sound_manager->prev = new;
    game->sound_manager = new;
}

void play_sound(game_t *game, char *name, float pitch)
{
    sfSound *sound;
    sfSoundBuffer *sbuf = get_sbuf(game, name);

    if (!sbuf) {
        printf("sound buffer is NULL\n");
        return;
    }
    sound = sfSound_create();
    if (!sound) {
        printf("Failed to create sound instance\n");
        return;
    }
    sfSound_setBuffer(sound, sbuf);
    sfSound_setPitch(sound, pitch);
    sfSound_play(sound);
    add_sound_to_list(game, sound);
}
