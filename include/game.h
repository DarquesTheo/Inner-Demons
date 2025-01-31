/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** game
*/

#ifndef GAME_H_
    #define GAME_H_
    #include <SFML/Graphics.h>

typedef struct player_s player_t;
typedef struct keybinds_s keybinds_t;
typedef struct inputs_s inputs_t;
typedef struct res_s res_t;
typedef struct menu_s menu_t;
typedef struct clocks_s clocks_t;
typedef struct anim_s anim_t;
typedef struct ui_s ui_t;
typedef struct room_s room_t;
typedef struct mouse_input_s mouse_input_t;
typedef struct sound_manager_s sound_manager_t;
typedef struct system_s system_t;
typedef struct game_menu_s game_menu_t;
typedef struct dialogue_s dialogue_t;

    #define SAVE_FILE "res/save/save.txt"

typedef enum {
    MAIN_MENU,
    GAME,
} status_t;

typedef struct game_info_s {
    status_t game_status;
    keybinds_t *keybinds;
    inputs_t *inputs;
    inputs_t *last_inputs;
    mouse_input_t *mouse;
    sfSprite *crosshair;
    int fps;
    sfVector2f last_mouse_pos;
    sfVector2f mouse_pos;
    sfVector2f local_mouse_pos;
    sfVector2f last_local_mouse_pos;
    int mouse_side;
    int sfx_vol;
    int music_vol;
    sfBool debug;
    sfBool in_menu;
    sfTexture *current_tileset;
} game_info_t;

typedef struct game_s {
    game_info_t *info;
    sfRenderWindow *window;
    res_t *res;
    menu_t *menu;
    player_t *player;
    clocks_t *clocks;
    anim_t *anims;
    ui_t *ui;
    room_t *map;
    sound_manager_t *sound_manager;
    system_t *system;
    game_menu_t *game_menu;
    dialogue_t *dialogue;
} game_t;

//events
void process_game_events(game_t *game, sfEvent event);
void process_mmenu_events(game_t *game, sfEvent event);
void player_events(game_t *game, sfEvent *event);

//exit function
void restart_game(game_t *game);
void go_home(game_t *game);

//init
sfRenderWindow *init_window(int f_flag);
game_t *init_prog(int f_flag);
game_info_t *init_game_info(game_t *game);

//free
void free_game_not_res_or_window(game_t *game);
void free_prog(game_t *game);

//main loop calls
void start_game(game_t *game);
void handle_menu(game_t *game);
void play_game(game_t *game, sfEvent event);

//save
void save(sfClock *clock);
int load(void);

#endif /* !GAME_H_ */
