/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** dialogue
*/

#ifndef DIALOGUE_H_
    #define DIALOGUE_H_
    #include <SFML/Graphics.h>

typedef struct game_s game_t;

typedef enum {
    DIALOGUE_WAIT,
    DIALOGUE_PLAY,
    DIALOGUE_COMPLETE,
    DIALOGUE_END,
} dialogue_state_t;

typedef struct dialogue_s {
    dialogue_state_t state;
    char *str;
    char *cur_str;
    sfText *text;
    sfRectangleShape *rect;
    sfClock *clock;
    sfSprite *sprite;
    int hint;
    int size;
    float wait_time;
    struct dialogue_s *next;
    struct dialogue_s *prev;
} dialogue_t;

void add_dialogue(game_t *game, char *str);
void draw_dialogue(game_t *game);
void advance_dialogue(game_t *game);
int act_dialogue(game_t *game);
void skip_dialogue(game_t *game);
void delete_dialogue(dialogue_t **list, dialogue_t *del);
void dial_boss(game_t *game, int boss);

#endif /* !DIALOGUE_H_ */
