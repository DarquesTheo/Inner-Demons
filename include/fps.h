/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** fps
*/

#ifndef FPS_H_
    #define FPS_H_
    #include "game.h"

//on each fps
void do_fps_clock(game_t *game);
void on_each_fps_player(game_t *game, float delta);
void on_each_fps_ui(game_t *game);
void on_each_fps_cursor(game_t *game);
void on_each_fps_room(game_t *game);
void on_each_fps_sound_manager(game_t *game);
void on_each_fps_anim_list(game_t *game, float delta, int layer);

#endif /* !FPS_H_ */
