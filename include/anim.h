/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** anim
*/

#ifndef ANIM_H_
    #define ANIM_H_
    #include <SFML/Graphics.h>
    #include <SFML/System/Vector2.h>
    #include "hitbox.h"

    #define HITMARKER_SPEED 50

typedef struct game_s game_t;
typedef struct mob_s mob_t;
typedef struct weapon_s weapon_t;
typedef struct res_s res_t;

typedef enum {
    ANIM_NONE,
    ANIM_HIT,
    ANIM_OBJ,
    ANIM_NPC,
    ANIM_BED,
    ANIM_PPROJ,
} anim_type_t;

typedef enum {
    COL_PLAYER,
    COL_PPROJ,
    COL_WALL,
    COL_OBJ,
    COL_ENEMY,
    COL_TIME,
    MAX_ENUM_COL_TYPE
} col_type_t;

typedef struct hit_list_s {
    mob_t *mob;
    struct hit_list_s *next;
    struct hit_list_s *prev;
} hit_list_t;

typedef struct col_s {
    sfBool player;
    sfBool ennemy;
    sfBool map;
    sfBool object;
    sfBool player_proj;
    hit_list_t *hit_list;
    char *sfx;
} col_t;

typedef struct anim_color_s {
    sfClock *color_clock;
    int alpha_decrease;
    int cadency; //times by second
} anim_color_t;

//any value equal to -1 will not be considerate
typedef struct anim_s {
    anim_type_t type;
    int layer;
    sfSprite *sprite;
    sfClock *clock;
    int dmg;
    int fps;
    sfIntRect rect;
    int img_width;
    sfVector2f move;
    float time_count;
    float duration;
    float speed;
    sfBool loop;
    col_t *col;
    int (*on_collide)(game_t *game, struct anim_s *ani, mob_t *mob,
        col_type_t type);
    hitbox_rect_t *hitbox;
    int nb_hit;
    weapon_t *wp;
    sfText *text;
    sfBool go_to_player;
    anim_color_t *color;
    struct anim_s *next;
    struct anim_s *prev;
} anim_t;

//get_default
anim_t *get_default_anim(void);
col_t *get_default_col(void);

//anim list
void anim_list(game_t *game);
void add_anim(game_t *game, anim_t *anim);
void add_anim_to_list(anim_t **list, anim_t *anim);
void delete_anim(anim_t **list, anim_t *del);
void anim_y_sort_add(anim_t **list, anim_t *anim);

//hit list
void add_mob_hit(hit_list_t **list, mob_t *mob);
int is_mob_in_hit_list(hit_list_t *list, mob_t *mob);

//collisions
int get_tile_point_col(game_t *game, sfVector2f pos);
int check_anim_col(game_t *game, anim_t *tmp);
int are_rect_colliding(sfRectangleShape *r1, sfRectangleShape *r2);
int are_hitbox_colliding(hitbox_rect_t *h1, hitbox_rect_t *h2);
int do_collide_function(anim_t *anim, game_t *game, mob_t *mob,
    col_type_t type);

//hitmarker
anim_t *get_hitmarker(int dmg, sfVector2f pos, res_t *res, sfBool crit);

//free
void free_anim_list(anim_t **list);

#endif /* !ANIM_H_ */
