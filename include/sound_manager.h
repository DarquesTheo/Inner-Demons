/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** sound_manager
*/

#ifndef SOUND_MANAGER_H_
    #define SOUND_MANAGER_H_
    #include <SFML/Audio.h>

typedef struct game_s game_t;

typedef struct sound_manager_s {
    sfSound *sound;
    struct sound_manager_s *next;
    struct sound_manager_s *prev;
} sound_manager_t;

void play_sound(game_t *game, char *name, float pitch);
void delete_sound(sound_manager_t **list, sound_manager_t *del);

#endif /* !SOUND_MANAGER_H_ */
