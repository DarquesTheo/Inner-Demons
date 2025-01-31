/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** objects
*/

#ifndef OBJECTS_H_
    #define OBJECTS_H_
    #include <SFML/Graphics.h>
    #include "hitbox.h"
    #define COIN_SPEED 500

typedef struct obj_res_s obj_res_t;
typedef struct game_s game_t;
typedef struct weapon_s weapon_t;
typedef struct room_s room_t;

typedef enum {
    POT_INTACT,
    POT_DESTROYED,

} pot_state_t;

typedef struct pot_s {
    sfSprite *sprite;
    hitbox_rect_t *hitbox;
    sfIntRect rect;
    pot_state_t state;
    struct pot_s *next;
    struct pot_s *prev;
} pot_t;

typedef struct spike_s {
    sfSprite *sprite;
    hitbox_rect_t *hitbox;
    sfIntRect rect;
    sfClock *clock;
    float time_buf;
    struct spike_s *next;
    struct spike_s *prev;
} spike_t;

typedef struct objects_s {
    pot_t *pots;
    spike_t *spikes;
} objects_t;

void init_room_objects(char *file, game_t *game, room_t *room);

//general object
void add_object(game_t *game, char *name, sfVector2f pos);

//pot
void add_pot(pot_t **pots, sfVector2f pos, sfTexture *tex);
void pot_on_collide(game_t *game, pot_t *pot);

//spike
void add_spike(spike_t **spikes, sfVector2f pos, sfTexture *tex);
void animate_spike(game_t *game, spike_t *spike);
void spike_on_collide(game_t *game, spike_t *spike);

//portal
int spawn_portal(game_t *game, sfVector2f pos);

//coins
void spawn_money(game_t *game, sfVector2f pos, char *type, sfBool sfx);
void spawn_random_money(game_t *game, sfVector2f pos, sfBool sfx);
void spawn_random_money_radius(game_t *game, sfVector2f pos,
    int radius, int amount);

//bed
void spawn_bed(game_t *game, sfVector2f pos);

//weapons
void spawn_weapon(game_t *game, sfVector2f pos, weapon_t *wp, int angle);
void spawn_random_weapon(game_t *game, sfVector2f pos, int angle);

//NPC
void spawn_mage_npc(game_t *game, sfVector2f pos);

//free
void free_objects(objects_t *obj);

#endif /* !OBJECTS_H_ */
