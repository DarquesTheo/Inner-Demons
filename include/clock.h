/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** clocks
*/

#ifndef CLOCKS_H_
    #define CLOCKS_H_
    #include <SFML/Graphics.h>

typedef struct clocks_s {
    sfClock *fps;
    sfClock *player_anim; //8fps
    sfClock *player_dash;
    sfClock *player_dash_smoke;
} clocks_t;

clocks_t *init_clocks(void);


#endif /* !CLOCKS_H_ */
