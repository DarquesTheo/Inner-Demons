/*
** EPITECH PROJECT, 2024
** free_artefact.c
** File description:
** free_artefact
*/

#include "artefact.h"

void free_artefact_struct(artefact_t *artefact)
{
    ui_line_artefact_t *next = NULL;

    for (ui_line_artefact_t *node = artefact->lines;
        node != NULL; node = next) {
        sfSprite_destroy(node->roll_quality);
        sfSprite_destroy(node->roll_stat);
        sfSprite_destroy(node->unlock);
        sfText_destroy(node->text_percent);
        sfText_destroy(node->text_stat);
        next = node->next;
        free(node);
    }
    sfClock_destroy(artefact->clock);
    sfSprite_destroy(artefact->bg);
    sfSprite_destroy(artefact->sprite);
}
