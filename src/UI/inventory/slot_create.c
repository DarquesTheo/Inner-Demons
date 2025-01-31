/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** slot_create
*/

#include "inventory.h"
#include "res.h"

slot_t *slot_create(void)
{
    slot_t *slot = malloc(sizeof(slot_t));

    slot->content = NULL;
    slot->icon = sfRectangleShape_create();
    return slot;
}

void init_slot_text(res_t *res, slot_t *slot)
{
    slot->lvl = sfText_create();
    sfText_setFont(slot->lvl, res->inv->font);
    sfText_setCharacterSize(slot->lvl, 15);
    sfText_setString(slot->lvl, "0");
}

//TODO change icon loading by a asset manager
slot_t *slot_create_default(res_t *res)
{
    slot_t *slot = malloc(sizeof(slot_t));
    sfTexture *icon = res->inv->slot;

    slot->content = NULL;
    slot->btn = button_create_default();
    slot->icon = sfRectangleShape_create();
    sfRectangleShape_setSize(slot->icon, (sfVector2f){SLOT_SIZE_X - 10,
        SLOT_SIZE_Y - 40});
    sfRectangleShape_setOrigin(slot->icon, (sfVector2f){(SLOT_SIZE_X - 10) / 2,
        (SLOT_SIZE_Y - 40) / 2});
    sfRectangleShape_setFillColor(slot->icon, sfTransparent);
    sfRectangleShape_rotate(slot->icon, -45);
    button_seticon(slot->btn, icon);
    button_setfillcolor(slot->btn, sfTransparent);
    button_seticoncolor(slot->btn, sfWhite);
    button_setsize(slot->btn, (sfVector2f){SLOT_SIZE_X, SLOT_SIZE_Y});
    button_set_colors(slot->btn, sfTransparent, sfTransparent, sfTransparent);
    init_slot_text(res, slot);
    return slot;
}
