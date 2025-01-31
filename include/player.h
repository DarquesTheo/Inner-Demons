/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** player
*/

#ifndef PLAYER_H_
    #define PLAYER_H_
    #include <SFML/System/Vector2.h>
    #include <SFML/Graphics.h>
    #include "game.h"
    #include "res.h"
    #include "hitbox.h"

    #define DASH_CD 0.5
    #define INVINCIBILITY_TIME 1
    #define WEAPON_NB 5

typedef struct game_s game_t;

typedef enum {
    WALKING,
    RUNNING,
    DASHING,
} player_state_t;

typedef enum pos_s {
    LEFT,
    RIGHT,
    TOP,
    BOTTOM,
    OUT,
} pos_t;

typedef struct weapon_s {
    char *name;
    void (*shoot)(game_t *, struct weapon_s *);
    sfSprite *sprite;
    float dmg;
    float angle_offset;
    float fire_rate;
    int lvl;
    int spray; //max angle of spray
    sfClock *clock;
    sfTexture *texture;
} weapon_t;

typedef struct pstate_s {
    sfBool can_move;
    sfBool can_attack;
    sfBool can_take_dmg;
    sfClock *invincibility;
} pstate_t;

typedef struct player_s {
    sfVector2f dir;
    sfSprite *sprite;
    sfIntRect rect;
    hitbox_rect_t *dep_hitbox;
    hitbox_rect_t *hitbox;
    float hp;
    float thp;
    int level;
    float xp;
    int coin;
    player_state_t state;
    pstate_t *states;
    weapon_t *wp1;
    weapon_t *wp2;
    sfVector2f input_dir_vec_on_dash;
    sfView *cam;
} player_t;

//init
player_t *init_player(game_t *game);

//weapons utils
sfVector2f get_bullet_start(sfSprite *sprite, float distance, float offset);
sfVector2f get_bullet_spawn(sfSprite *weapon, sfVector2f offset);
void set_bullet_dep(game_t *game, weapon_t *wp, anim_t *anim);
void free_weapon(weapon_t *wp);
sfVector2f get_muzzle_pos(sfSprite* sprite, sfVector2f muzzlepos);
sfTexture *get_weapon_icon(weapon_t *weapon);

//create weapons
weapon_t *create_wind_staff(res_t *res);
weapon_t *create_ak47(res_t *res);
weapon_t *create_smg(res_t *res);
weapon_t *create_shotgun(res_t *res);
weapon_t *create_laser_gun(res_t *res);
weapon_t *create_canon(game_t *game);

//player
sfVector2f get_player_delta_vector(game_t *game, float delta);
sfVector2f get_input_dir_vector(game_t *game);
void anim_player(game_t *game);
void handle_player_dash(game_t *game);
void start_player_dash(game_t *game);
void set_player_sprite(game_t *game, sfVector2f dir);
void set_player_idle(game_t *game);
float get_player_speed(game_t *game);
void actz_player_anim(game_t *game, int is_new_dir);
void player_take_dmg(game_t *game, float dmg);
void player_gain_health(game_t *game, float amt);
void player_shoot(game_t *game);
void player_gain_coin(game_t *game, int amt);

//move
void player_w_spike_col(game_t *game);
void move_player(game_t *game, float delta);


#endif /* !PLAYER_H_ */
