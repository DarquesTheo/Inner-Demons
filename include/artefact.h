/*
** EPITECH PROJECT, 2024
** artefact.h
** File description:
** artefact
*/

#ifndef ARTEFACT_H_
    #define ARTEFACT_H_
    #include "SFML/Graphics.h"
    #include "res.h"
    #define MAX_EXP_X 300

typedef struct res_artefact_s {
    sfTexture *exp_bar;
    sfTexture *bg;
    sfTexture *artefact;
    sfTexture *roll_stat;
    sfTexture *roll_quality;
    sfTexture *unlock;
    sfTexture *back;
    sfTexture *stat_table;
    sfTexture *hp_bar;
    sfFont *font;
} res_artefact_t;

typedef enum stat_type_s {
    DAMAGE,
    ATTACK_SPEED,
    MOVEMENT_SPEED,
    ACCURACY,
    LUCK,
    INTELLIGENCE,
    DODGE,
    LIFESTEAL,
    DOUBLE_SHOT,
    COUP_CRITIQUE
} stat_type_t;

typedef struct ui_line_artefact_s {
    int index;
    int quality;
    sfText *text_stat;
    sfText *text_percent;
    stat_type_t type;
    sfBool unlocked;
    struct ui_line_artefact_s *next;
    sfSprite *unlock;
    sfSprite *roll_stat;
    sfSprite *roll_quality;
} ui_line_artefact_t;

typedef struct range_artefact_s {
    int quality_max[10];
    int quality_min[10];
    float quality_incr[10];
    int quality_cap[10];
    sfText *text[10];
    char *stat_str[10];
} range_artefact_t;

typedef struct artefact_s {
    sfClock *clock;
    sfSprite *bg;
    sfSprite *sprite;
    sfSprite *back;
    sfSprite *stat_table;
    sfIntRect rect;
    struct ui_line_artefact_s *lines;
    int level;
    sfBool visible;
    sfBool on_click;
    sfText *text_level;
    sfText *text_roll_price;
    range_artefact_t *range;
    sfRectangleShape *exp_bar;
    sfSprite *exp_bar_sprite;
    int max_exp;
    int cur_exp;
} artefact_t;

artefact_t *init_artefact_struct(res_t *res);
void draw_artefact_ui(sfRenderWindow *window, artefact_t *node, game_t *game);
void roll_stat_line(ui_line_artefact_t *line);
void roll_quality_line(ui_line_artefact_t *line, artefact_t *artefact);
void add_normal_stat_line(game_t *game);
void add_boss_stat_line(game_t *game, stat_type_t type);
void add_stat_line(ui_line_artefact_t **list, stat_type_t type, res_t *res);
void place_lines(ui_line_artefact_t *list);
void free_artefact_struct(artefact_t *artefact);
float get_multiplicator_stat(stat_type_t type, game_t *game);
sfBool need_coin(game_t *game, int type, ui_line_artefact_t *line);
void remove_coin(game_t *game, int type, ui_line_artefact_t *line);
int get_max_range(stat_type_t type, artefact_t *artefact);
int get_min_range(stat_type_t type, artefact_t *artefact);
void draw_lines_artefact(sfRenderWindow *window,
    ui_line_artefact_t *lines, game_t *game);
void draw_lines_artefact3(sfRenderWindow *window, game_t *game);
void draw_lines_artefact2(sfRenderWindow *window, ui_line_artefact_t *line);
void draw_exp_bar(game_t *game);
void get_exp_from_mob(game_t *game, mob_t *mob);
void draw_artefact_ui2(sfRenderWindow *window, artefact_t *node, game_t *game);

#endif
