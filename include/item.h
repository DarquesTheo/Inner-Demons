/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** item
*/

#ifndef ITEM_H_
    #define ITEM_H_
    #include <SFML/Graphics.h>

typedef enum {
    WEAPON,
    WA, //weapon artifact
} item_type_t;

typedef struct item_s {
    item_type_t type;
    void *obj;
} item_t;

sfSprite *get_item_sprite(item_t *item);

#endif /* !ITEM_H_ */
