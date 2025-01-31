/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** launch_dials
*/

#include "game.h"
#include "dialogue.h"

void dial_boss2(game_t *game, int boss)
{
    if (boss == 4) {
        add_dialogue(game, "uber_5.txt");
        add_dialogue(game, "uber_4.txt");
        add_dialogue(game, "uber_3.txt");
        add_dialogue(game, "uber_2.txt");
        add_dialogue(game, "uber_1.txt");
    }
}

void dial_boss(game_t *game, int boss)
{
    if (boss == 1) {
        add_dialogue(game, "anger_3.txt");
        add_dialogue(game, "anger_2.txt");
        add_dialogue(game, "anger_1.txt");
    }
    if (boss == 2) {
        add_dialogue(game, "anxiety_3.txt");
        add_dialogue(game, "anxiety_2.txt");
        add_dialogue(game, "anxiety_1.txt");
    }
    if (boss == 3) {
        add_dialogue(game, "despair_3.txt");
        add_dialogue(game, "despair_2.txt");
        add_dialogue(game, "despair_1.txt");
    }
    dial_boss2(game, boss);
}
