/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** res
*/

#ifndef RES_H_
    #define RES_H_
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include "game.h"
    #include "enemies.h"
    #include "heart.h"
    #include "death.h"
    #include "interact.h"

typedef struct res_mob_s res_mob_t;
typedef struct res_projectile_mob_s res_projectile_mob_t;
typedef struct linked_list_s linked_list_t;
typedef struct res_artefact_s res_artefact_t;

typedef struct tilesets_s {
    sfTexture *floor1;
    sfTexture *floor2;
    sfTexture *floor3;
    sfTexture *floor4;
    sfTexture *spawn;
} tilesets_t;

typedef struct sbuf_list_s {
    char *name;
    sfSoundBuffer *soundbuffer;
    struct sbuf_list_s *next;
    struct sbuf_list_s *prev;
} sbuf_list_t;

typedef struct tex_list_s {
    char *name;
    sfTexture *tex;
    struct tex_list_s *next;
    struct tex_list_s *prev;
} tex_list_t;

//the sprites are 64x64px
//8 fps for movement animation looks great
typedef struct player_res_s {
    sfTexture *move_up;
    sfTexture *move_down;
    sfTexture *move_left;
    sfTexture *move_right;
    sfTexture *dash_up;
    sfTexture *dash_down;
    sfTexture *dash_left;
    sfTexture *dash_right;
    sfTexture *idle_up;
    sfTexture *idle_down;
    sfTexture *idle_left;
    sfTexture *idle_right;
} player_res_t;

typedef struct weapons_res_s {
    sfTexture *wind_staff;
    sfTexture *wind_staff_bullet;
    sfTexture *tornado_col;
    sfTexture *ak47;
    sfTexture *ak47_bullet;
    sfTexture *ak47_col;
    sfTexture *smg;
    sfTexture *smg_bullet;
    sfTexture *shotgun;
    sfTexture *shotgun_bullet;
    sfTexture *laser_gun;
    sfTexture *laser_gun_bullet;
} weapons_res_t;

typedef struct obj_res_s {
    sfTexture *pot;
    sfTexture *spike;
    sfTexture *pot_explosion;
    sfTexture *portal_blue;
} obj_res_t;

typedef struct inventory_res_s {
    sfTexture *slot;
    sfTexture *heart_full;
    sfTexture *heart_three;
    sfTexture *heart_semi;
    sfTexture *heart_quarter;
    sfTexture *heart_empty;
    sfTexture *coin;
    sfTexture *shop_bg;
    sfTexture *equip_left;
    sfTexture *equip_right;
    sfTexture *delete;
    sfTexture *interactbg;
    sfTexture *shopbtn;
    sfTexture *sell;
    sfTexture *merge;
    sfFont *font;
} inv_res_t;

typedef struct menu_res_s {
    sfTexture *home;
    sfTexture *restart;
    sfTexture *died;
} menu_res_t;

typedef struct fonts_s {
    sfFont *dialogue_font;
} fonts_t;

typedef struct res_s {
    player_res_t *player_res;
    sfTexture *crosshair1;
    weapons_res_t *weapons;
    tilesets_t *tilesets;
    obj_res_t *obj_res;
    res_mob_t *mob;
    res_projectile_mob_t *projectile_mob;
    sbuf_list_t *sbuf_list;
    tex_list_t *tex_list;
    linked_list_t *pool_floor1;
    linked_list_t *pool_floor2;
    linked_list_t *pool_floor3;
    inv_res_t *inv;
    menu_res_t *menu;
    res_artefact_t *artefact;
    fonts_t *fonts;
} res_t;

res_t *init_res(void);
player_res_t *init_player_res(void);
sfSprite *init_crosshair(res_t *res);
weapons_res_t *init_weapons_res(void);
tilesets_t *init_tilesets(void);
obj_res_t *init_obj_res(void);
void free_res(res_t *res);
heart_t *init_heart(res_t *res, int max_health);
menu_res_t *init_menu_res(void);
death_menu_t *init_death_menu(res_t *res);
res_artefact_t *init_res_artefact(void);
fonts_t *init_fonts(void);
interact_t *init_interact_menu(res_t *res);

//sbuf list
void init_sbufs(game_t *game);;
void add_sbuf(game_t *game, char *res_path, char *name);
sfSoundBuffer *get_sbuf(game_t *game, char *name);
void delete_sbuf(sbuf_list_t **list, sbuf_list_t *del);

//tex list
void init_tex_list(game_t *game);
void add_tex(game_t *game, char *res_path, char *name);
void delete_tex(tex_list_t **list, tex_list_t *del);
sfTexture *get_tex(game_t *game, char *name);
sfTexture *get_tex_from_list(tex_list_t *list, char *name);
int is_tex_in_list(tex_list_t *list, char *name);
inv_res_t *init_inv_res(void);

#endif /* !RES_H_ */
