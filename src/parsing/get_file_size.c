/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** get_file_size
*/

#include "game.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int get_file_size(char *path)
{
    struct stat sb;

    if (stat(path, &sb) == -1) {
        perror("stat");
        return -1;
    }
    return sb.st_size;
}
