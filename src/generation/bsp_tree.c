/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** bsp_tree
*/

/* #include "game.h"
#include "generation.h"
#include "const.h"

leaf_t *create_leaf(sfVector2i tl, sfVector2i br, leaf_t *next, int division)
{
    leaf_t *leaf = malloc(sizeof(leaf_t));

    leaf->tl = tl;
    leaf->br = br;
    leaf->division = division;
    leaf->next = next;
    return leaf;
}

int get_random_number(int lower, int upper)
{
    int result = rand() % (upper - lower + 1) + lower;
    printf("RESULT MODULO : %d\n", result);
    return result;
}

int is_good_leaf_wratio(sfVector2i tl, sfVector2i br)
{
    sfVector2f size = {br.x - tl.x, br.y - tl.y};

    printf("%f\n", size.x / size.y);
    if (size.x / size.y < W_RATIO)
        return 0;
    return 1;
}

int is_good_leaf_hratio(sfVector2i tl, sfVector2i br)
{
    sfVector2f size = {br.x - tl.x, br.y - tl.y};

    if (size.y / size.x < H_RATIO)
        return 0;
    return 1;
}

void split_leaf(leaf_t *leaf)
{
    sfVector2i size = {leaf->br.x - leaf->tl.x, leaf->br.y - leaf->tl.y};
    sfVector2i tmp;
    int new;

    if (rand() % 2 == 0) {
        new = get_random_number(MIN_ROOM_SIZE_X, size.x - MIN_ROOM_SIZE_X);
        tmp = v2i(leaf->tl.x + new, leaf->tl.y);
        if (!is_good_leaf_wratio(tmp, leaf->br)
        || !is_good_leaf_wratio(leaf->tl, v2i(new, leaf->br.y))) {
            return;
        }
        leaf->next = create_leaf(tmp, leaf->br,
        leaf->next, leaf->division + 1);
        leaf->br.x = new;
    } else {
        new = get_random_number(MIN_ROOM_SIZE_Y, size.y - MIN_ROOM_SIZE_Y);
        tmp = v2i(leaf->tl.x, leaf->tl.y + new);
        if (!is_good_leaf_hratio(tmp, leaf->br)
        || !is_good_leaf_hratio(leaf->tl, v2i(leaf->br.x, new))) {
            return;
        }
        leaf->next = create_leaf(tmp, leaf->br, leaf->next,
        leaf->division + 1);
        leaf->br.y = new;
    }
    leaf->division += 1;
}

void draw_horizontal_line(room_t *map, int x1, int x2, int y) {
    if (y < 0 || y >= map->size.y) {
        printf("Y coordinate is out of bounds.\n");
        return;
    }
    if (x1 < 0) {
        x1 = 0;
    }
    if (x2 >= map->size.x) {
        x2 = map->size.x - 1;
    }
    for (int x = x1; x <= x2; x++) {
        map->int_map[y * map->size.x + x] = 1;
    }
}

void draw_vertical_line(room_t *map, int x, int y1, int y2) {
    if (x < 0 || x >= map->size.x) {
        printf("X coordinate is out of bounds.\n");
        return;
    }
    if (y1 < 0) {
        y1 = 0;
    }
    if (y2 >= map->size.y) {
        y2 = map->size.y - 1;
    }
    for (int y = y1; y <= y2; y++) {
        map->int_map[y * map->size.x + x] = 1;
    }
}

void print_square_on_int_map(room_t *room, sfVector2i tl, sfVector2i br)
{
    draw_horizontal_line(room, tl.x, br.x, tl.y);
    draw_horizontal_line(room, tl.x, br.x, br.y);
    draw_vertical_line(room, tl.x, tl.y, br.y);
    draw_vertical_line(room, br.x, tl.y, br.y);
}

void split_at_level(leaf_t *leaf, int division)
{
    int exit = 0;

    while (!exit) {
        exit = 1;
        for (leaf_t *tmp = leaf; tmp; tmp = tmp->next) {
            if (tmp->division < division) {
                split_leaf(tmp);
                exit = 0;
            }
        }
    }
}

room_t *bsp_tree(void)
{
    room_t *map = malloc(sizeof(room_t));
    map->size = (sfVector2i){70, 70};
    map->int_map = malloc(sizeof(int) * 70 * 70);
    leaf_t *main_leaf = create_leaf(v2i(0, 0), (sfVector2i){map->size.x - 1,
    map->size.y - 1}, NULL, 0);

    split_at_level(main_leaf, 3);
    for (int i = 0; i < map->size.x * map->size.y; i++) {
        map->int_map[i] = -1;
    }
    for (leaf_t *tmp = main_leaf; tmp; tmp = tmp->next) {
        print_square_on_int_map(map, tmp->tl, tmp->br);
    }
    print_int_map(map);
    return map;
}
 */
