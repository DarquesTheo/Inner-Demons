/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** get_files_from_dir
*/

#include "mylib.h"
#include "map.h"
#include <dirent.h>
#include <stdlib.h>

static char *make_full_name(const char *dir_path, const char *file_name)
{
    char *full_name;
    char *complete_dir_path;

    if (dir_path[my_strlen(dir_path) - 1] != '/') {
        complete_dir_path = concat(dir_path, "/");
        full_name = concat(complete_dir_path, file_name);
        free(complete_dir_path);
    } else {
        full_name = concat(dir_path, file_name);
    }
    return full_name;
}

static void add_node(linked_list_t **list, char *pathname, char *name)
{
    linked_list_t *new = malloc(sizeof(linked_list_t));

    new->data = make_full_name(pathname, name);
    new->next = *list;
    *list = new;
}

linked_list_t *list_dir_files(char *pathname)
{
    DIR *dir = opendir(pathname);
    struct dirent *dir_content = readdir(dir);
    linked_list_t *list = NULL;

    while (dir_content != NULL) {
        if (dir_content->d_name[0] != '.') {
            add_node(&list, pathname, dir_content->d_name);
        }
        dir_content = readdir(dir);
    }
    closedir(dir);
    return list;
}
