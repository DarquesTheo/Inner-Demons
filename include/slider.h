/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** slider
*/

#ifndef SLIDER_H_

    #define SLIDER_H_
    #include "SFML/Graphics.h"


typedef struct slider_s {
    float value;
    sfRectangleShape *rect;
    sfRectangleShape *cursor;
    sfBool (*is_clicked)(struct slider_s *, sfVector2f);
    void (*on_pressed)(struct slider_s *, sfVector2f);
    sfBool visible;
}slider_t;

// SLIDER LIB  //

sfBool is_slider_pressed(slider_t *slider, sfVector2f pos);
slider_t *slider_create(void);
slider_t *slider_create_default(void);
void slider_pressed(slider_t *slider, sfVector2f pos);
void slider_setposition(slider_t *slider, sfVector2f pos);
void sfrenderwindow_drawslider(sfRenderWindow *window, slider_t *slider);
float slider_getvalue(slider_t *slider);
void slider_updatevalue(slider_t *slider, float value);

#endif /* !SLIDER_H_ */
