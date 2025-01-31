/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** save
*/

#include "game.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void erase_file(char *filename)
{
    FILE *file = fopen(filename, "w");

    if (file)
        fclose(file);
}

int load(void)
{
    FILE *file = fopen(SAVE_FILE, "r");
    char buff[50] = {0};

    if (file == NULL)
        return 0;
    fread(buff, 50, 1, file);
    fclose(file);
    return atoi(buff);
}

void save(sfClock *clock)
{
    FILE *file;
    char buff[256];
    sfTime time;

    erase_file(SAVE_FILE);
    file = fopen(SAVE_FILE, "w+");
    if (file == NULL)
        return;
    if (clock == NULL) {
        fclose(file);
        return;
    }
    time = sfClock_getElapsedTime(clock);
    sprintf(buff, "%f", sfTime_asSeconds(time));
    fwrite(buff, strlen(buff), 1, file);
    fclose(file);
}
