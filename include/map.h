/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** map
*/

#ifndef MAP_H_
    #define MAP_H_
    #include <SFML/System/Vector2.h>
    #include <SFML/Graphics.h>

typedef struct game_s game_t;
typedef struct objects_s objects_t;
typedef struct mob_s mob_t;
typedef struct res_s res_t;

typedef struct linked_list_s {
    void *data;
    struct linked_list_s *next;
} linked_list_t;

typedef struct room_s {
    sfVector2i size;
    sfVector2f scale;
    sfVector2f transform;
    sfVector2i tilesize;
    int *collisions;
    int *int_layer1;
    int *int_layer2;
    sfVertexArray *layer1;
    sfVertexArray *layer2;
    objects_t *objects;
    mob_t *mobs;
    sfVector2f player;
    sfVector2f portal;
} room_t;

//generation
room_t *bsp_tree(void);
void set_map(game_t *game, char *path);

//tilemaps
void test_tilemap(game_t *game);
sfVertexArray *load_tilemap(sfTexture *tileset,
    sfVector2i tile_size, int *tiles, sfVector2i dim);
room_t *read_map_file_csv(char *path);
int get_file_size(char *path);
char *get_file_content(char *path);
room_t *get_map_from_lua(char *path_to_lua, game_t *game);
char *get_file_content(char *path);
void remove_chars(char *str, char *rm);
char *get_text_between_pointers(char *start_ptr, char *end_ptr);
char *get_text_between_curlys(char *pos_open_curly);
char *get_lua_variable_value(char *lua, char *variable);
void set_room_collisions(room_t *room, char *file);
int *get_int_map(char *map, sfVector2i dim);
sfVector2f get_rand_tile(game_t *game);

//list
linked_list_t *list_dir_files(char *pathname);
int get_list_size(linked_list_t *list);
char *get_random_map_file(game_t *game);

//free
void free_current_map(game_t *game);

//utils
sfVector2f get_room_center(room_t *room);
sfVector2i get_rand_pos_in_room(room_t *room);

#endif /* !MAP_H_ */
