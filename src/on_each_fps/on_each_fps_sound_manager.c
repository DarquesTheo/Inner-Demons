/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** on_each_fps_sound_manager
*/

#include "game.h"
#include "sound_manager.h"

void on_each_fps_sound_manager(game_t *game)
{
    sound_manager_t *next = NULL;

    for (sound_manager_t *tmp = game->sound_manager; tmp; tmp = next) {
        next = tmp->next;
        if (sfSound_getStatus(tmp->sound) == sfStopped) {
            delete_sound(&(game->sound_manager), tmp);
        }
    }
}
