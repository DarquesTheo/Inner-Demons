/*
** EPITECH PROJECT, 2024
** showtab.c
** File description:
** display tab content if they are chars
*/

#include "mylib.h"

void show_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        my_putstr(tab[i]);
    }
}
