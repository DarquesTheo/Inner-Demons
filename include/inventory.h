/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** inventory
*/

#ifndef INVENTORY_H_
    #define INVENTORY_H_
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <stdlib.h>
    #include "button.h"
    #include "res.h"

/*  --------------------  */
/*  ------  ENUM  ------  */
/*  --------------------- */

typedef enum {
    OPEN,
    CLOSED,
} inv_status_t;

/*  ----------------------  */
/*  ------  MACRO   ------  */
/*  ----------------------  */

    #define SLOT_SIZE_X 62
    #define SLOT_SIZE_Y 62


/*  ----------------------  */
/*  ------  STRUCT  ------  */
/*  ----------------------  */

typedef struct slot_s {
    button_t *btn;
    sfRectangleShape *icon;
    void *content;
    sfText *lvl;
} slot_t;

//A 2d array of (void *) // Usage inv[y][x]
typedef struct inventory_s {
    int size_x;
    int size_y;
    slot_t ***inv;
    sfBool active;
    sfTexture *(*geticon)(void *);
} inventory_t;

/*  ------------------------  */
/*  ------  FUNCTION  ------  */
/*  ------------------------  */

/*  ----------------  */
/*  ----  SLOT  ----  */
/*  ----------------  */

slot_t *slot_create(void);
slot_t *slot_create_default(res_t *res);

//getter
sfBool slot_isempty(slot_t *slot);
void *inventory_getslotcontent(inventory_t *inventory, sfVector2i pos);

//setter
void slot_setposition(slot_t *slot, sfVector2f pos);
void inventory_insertitem(inventory_t *inventory, void *item, sfVector2i pos);
sfBool try_inventory_insertitem(inventory_t *inventory, void *item,
    sfVector2i pos);
sfBool inventory_additem(inventory_t *inventory, void *item);
void slot_refreshicon(slot_t *slot);

//draw
void sfrenderwindow_drawslot(sfRenderWindow *window, slot_t *slot);

/*  ----------------  */
/*  --  INVENTORY  -- */
/*  ----------------  */

inventory_t *inventory_create(sfVector2i size, sfVector2f pos, res_t *res);

//getter

//setter
void inventory_seticongetter(inventory_t *inv, sfTexture *(*geticon)(void *));
void inventory_applyiconslot(inventory_t *inv, sfVector2i pos);
void inventory_toggle(inventory_t *inv);

//draw
void sfrenderwindow_drawinventory(sfRenderWindow *window, inventory_t *inv);

//free
void inventory_destroy(inventory_t *inv, void(*freefnc)(void *));

#endif /* !INVENTORY_H_ */
