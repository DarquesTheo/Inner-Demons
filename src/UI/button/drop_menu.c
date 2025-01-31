/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** drop_menu
*/

#include "button.h"

drop_menu_t *drop_menu_create(void)
{
    drop_menu_t *drop_menu = malloc(sizeof(drop_menu_t));

    drop_menu->button = button_create_default();
    drop_menu->menu_box = sfRectangleShape_create();
    sfRectangleShape_setFillColor(drop_menu->menu_box,
        (sfColor){200, 200, 200, 255});
    drop_menu->state = NONE;
    drop_menu->options = NULL;
    return drop_menu;
}

void drop_menu_addoptions(drop_menu_t *drop_menu, void *callback_fnc,
    sfVector2f pos)
{
    button_t *btn = button_create_default();

    button_setcallback(btn, callback_fnc);
    button_setposition(btn, pos);
    drop_menu->options = add_menu_btn(drop_menu->options, btn);
}

void sfrenderwindow_drawdropmenu(sfRenderWindow *window,
    drop_menu_t *drop_menu)
{
    menu_btn_t *tmp = NULL;

    if (drop_menu == NULL)
        return;
    tmp = drop_menu->options;
    if (drop_menu->state == HOVER)
        sfRenderWindow_drawRectangleShape(window, drop_menu->menu_box, NULL);
    sfrenderwindow_drawbutton(window, drop_menu->button);
    if (drop_menu->state == HOVER) {
        while (tmp != NULL) {
            sfrenderwindow_drawbutton(window, tmp->button);
            tmp = tmp->next;
        }
    }
}

static void options_hover(drop_menu_t *drop_menu, sfVector2f pos)
{
    menu_btn_t *tmp = drop_menu->options;

    while (tmp != NULL) {
        tmp->button->is_hover(tmp->button, pos);
        tmp = tmp->next;
    }
}

void drop_menu_hover(drop_menu_t *drop_menu, sfVector2f pos)
{
    if (drop_menu->state == NONE) {
        if (drop_menu->button->is_hover(drop_menu->button, pos)) {
            drop_menu->state = HOVER;
            return;
        }
    }
    if (drop_menu->state == HOVER) {
        if (!is_in_rectangle(drop_menu->menu_box, pos)) {
            drop_menu->state = NONE;
            return;
        }
        options_hover(drop_menu, pos);
        return;
    }
    drop_menu->state = NONE;
}

/*
void drop_menu_clicked(drop_menu_t *drop_menu, sfVector2f pos, app_t *app)
{
    menu_btn_t *tmp = drop_menu->options;

    if (drop_menu->state != HOVER)
        return;
    while (tmp != NULL) {
        if (tmp->button->is_clicked(tmp->button, pos))
            tmp->button->on_pressed(app);
        tmp = tmp->next;
    }
}*/
