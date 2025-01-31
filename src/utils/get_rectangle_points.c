/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** get_rectangle_points
*/

#include "utils.h"
#include "vector.h"
#include <stdlib.h>

static void get_rectangle_points2(sfVector2f size, sfVector2f *points,
    int nb_by_edge)
{
    sfVector2f cur = v2f(0, 0);
    int i = 0;

    for (; cur.x < size.x; i++) {
        points[i] = cur;
        cur.x += size.x / nb_by_edge;
    }
    for (; cur.y < size.y; i++) {
        points[i] = cur;
        cur.y += size.y / nb_by_edge;
    }
    for (; cur.x > 0; i++) {
        points[i] = cur;
        cur.x -= size.x / nb_by_edge;
    }
    for (; cur.y > 0; i++) {
        points[i] = cur;
        cur.y -= size.y / nb_by_edge;
    }
}

sfVector2f *get_rectangle_points(int nb_by_edge, sfRectangleShape *rect)
{
    sfVector2f *points = malloc(sizeof(sfVector2f) * (nb_by_edge * 4 + 4));
    sfVector2f size = sfRectangleShape_getSize(rect);
    sfVector2f pos = sfRectangleShape_getPosition(rect);

    pos = get_vector_difference(v2f(size.x / 2, size.y / 2), pos);
    get_rectangle_points2(size, points, nb_by_edge);
    for (int i = 0; i < nb_by_edge * 4; i++) {
        points[i] = add_vectors(points[i], pos);
    }
    return points;
}
