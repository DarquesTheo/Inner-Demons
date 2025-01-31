/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** get_file_content
*/

#include "game.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "map.h"
#include <stdlib.h>
#include <stdio.h>

char *get_file_content(char *path)
{
    int size = get_file_size(path);
    int fd = open(path, O_RDONLY);
    char *result = malloc(size + 1);

    if (fd == -1) {
        perror("open");
        return NULL;
    }
    read(fd, result, size);
    close(fd);
    result[size] = 0;
    return result;
}
