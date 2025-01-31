/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** button
*/

#include "SFML/Graphics.h"

#ifndef BUTTON_H_

    #define BUTTON_H_
    #include "stdlib.h"


enum e_button_state {
    NONE,
    HOVER,
    PRESSED,
    RELEASED
};

    #define IS_HOVER(button) (button->state == HOVER) ? sfTrue : sfFalse
    #define IS_PRESSED(button) (button->state == PRESSED) ? sfTrue : sfFalse
    #define IS_RELEASED(button) (button->state == RELEASED) ? sfTrue : sfFalse

    #define DEFAULT_COLOR sfColor(255, 255, 255, 255)
    #define HOVER_COLOR sfColor(200, 200, 200, 255)
    #define PRESSED_COLOR sfColor(150, 150, 150, 255)

typedef struct button_color_s {
    sfColor c_default;
    sfColor c_hover;
    sfColor c_pressed;
}button_color_t;

typedef struct button_s {
    sfRectangleShape *rect;
    sfRectangleShape *icon;
    sfBool (*is_clicked)(struct button_s *, sfVector2f);
    sfBool (*is_hover)(struct button_s *, sfVector2f);
    void (*on_pressed)(void *);
    sfBool visible;
    enum e_button_state state;
    button_color_t *color;
}button_t;

sfBool is_button_pressed(button_t *button, sfVector2f pos);
sfBool is_button_hover(button_t *button, sfVector2f pos);
button_t *init_button(sfVector2f position, sfVector2f size);

sfRectangleShape *init_rectangle(sfVector2f position, sfVector2f size);
sfBool is_in_rectangle(sfRectangleShape *rect, sfVector2f position);

typedef struct menu_btn_s {
    button_t *button;
    struct menu_btn_s *next;
}menu_btn_t;

typedef struct drop_menu_s {
    button_t *button;
    sfRectangleShape *menu_box;
    menu_btn_t *options;
    enum e_button_state state;
}drop_menu_t;

//  LINKED LIST //

menu_btn_t *add_menu_btn(menu_btn_t *menu_btn, button_t *button);

//  DROP MENU  //

drop_menu_t *drop_menu_create(void);
void drop_menu_addoptions(drop_menu_t *drop_menu, void *callback_fnc,
    sfVector2f pos);
void sfrenderwindow_drawdropmenu(sfRenderWindow *window,
    drop_menu_t *drop_menu);
void drop_menu_hover(drop_menu_t *drop_menu, sfVector2f pos);

//  BUTTON LIB //

button_t *button_create(void);
void button_setsize(button_t *button, sfVector2f size);
void button_setposition(button_t *button, sfVector2f pos);
void button_setcallback(button_t *button, void (*callback_func)(void *));
void sfrenderwindow_drawbutton(sfRenderWindow *window, button_t *button);
void button_setfillcolor(button_t *button, sfColor color);
button_t *button_create_default(void);
void button_seticon(button_t *button, sfTexture *texture);
void button_seticoncolor(button_t *button, sfColor color);
void destroy_button(button_t *btn);
void button_set_colors(button_t *button, sfColor defaut, sfColor hover,
    sfColor pressed);

#endif /* !BUTTON_H_ */
