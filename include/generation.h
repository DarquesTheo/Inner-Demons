/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** generation
*/

#ifndef GENERATION_H_
    #define GENERATION_H_
    #include "game.h"

typedef struct leaf_s {
    sfVector2i tl; //top left
    sfVector2i br; //bottom right
    int division;
    struct leaf_s *next;
} leaf_t;

#endif /* !GENERATION_H_ */
