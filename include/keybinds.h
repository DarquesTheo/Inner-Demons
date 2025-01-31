/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** keybinds
*/

#ifndef KEYBINDS_H_
    #define KEYBINDS_H_
    #include <SFML/Window/Event.h>

typedef struct keybinds_s {
    sfKeyCode player_up;
    sfKeyCode player_down;
    sfKeyCode player_left;
    sfKeyCode player_right;
    sfKeyCode player_dash;
    sfKeyCode toggle_inventory;
    sfKeyCode toggle_shop;
} keybinds_t;

typedef struct inputs_s {
    sfBool player_up;
    sfBool player_down;
    sfBool player_left;
    sfBool player_right;
    sfBool toggle_shop;
} inputs_t;

typedef struct mouse_input_s {
    sfBool left_click;
    sfBool right_click;
} mouse_input_t;

keybinds_t *init_keybinds(void);
inputs_t *init_inputs(void);
mouse_input_t *init_mouse_input(void);

#endif /* !KEYBINDS_H_ */
