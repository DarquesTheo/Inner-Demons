/*
** EPITECH PROJECT, 2024
** enemies_stats.c
** File description:
** enemies stats struct
*/

#include "enemies.h"

stats_mob_t stats_table[I_MAX_ENEMIES] = {
    {200, 200, 200, 600, 300, 2},
    {100, 100, 100, 1000, 600, 1},
    {75, 75, 400, 300, 100, 1},
    {150, 150, 200, 10000, 0, 1},
    {150, 150, 120, 600, 300, 1.5},
    {125, 125, 150, 800, 500, 0.5},
    {2000, 2000, 150, 200, 50, 4},
    {1600, 1600, 150, 1000, 500, 2},
    {1000, 1000, 900, 100000, 0, 0.5}
};

projectile_t projectile_table[I_MAX_ENEMIES] = {
    {6, 0, 600, 15, 1, 0},
    {5, 0, 900, 10, 1, 0},
    {8, 0, 600, 10, 3, 25},
    {5, 0, 400, 90, 4, 90},
    {3, 0, 500, 20, 2, 20},
    {5, 0, 300, 50, 5, 30},
    {3, 0, 700, 20, 10, 10},
    {11, 0, 500, 20, 10, 10},
    {10, 0, 600, 23, 74, 5.64}
};
