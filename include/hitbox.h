/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** hitbox
*/

#ifndef HITBOX_H_
    #define HITBOX_H_
    #include <SFML/Graphics.h>

typedef struct hitbox_rect_s {
    sfRectangleShape *rect;
    sfVector2f offset;
} hitbox_rect_t;

hitbox_rect_t *create_rect_hitbox(sfVector2f size, sfVector2f offset);
void place_sprite_hitbox(hitbox_rect_t *hitbox, sfSprite *sprite);
void free_hitbox(hitbox_rect_t *hitbox);

#endif /* !HITBOX_H_ */
