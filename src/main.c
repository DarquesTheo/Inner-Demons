/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** main
*/

#include "game.h"
#include "mylib.h"
#include "menu.h"
#include "sound_manager.h"

void launcher(int f_flag)
{
    game_t *game = init_prog(f_flag);
    sfEvent event;

    game->menu->f_flag = f_flag;
    while (sfRenderWindow_isOpen(game->window)) {
        switch (game->info->game_status) {
            case (MAIN_MENU):
                handle_menu(game);
                process_mmenu_events(game, event);
            break;
            case (GAME):
                play_game(game, event);
            break;
        }
    }
    free_prog(game);
}

void option(int write)
{
    if (write) {
        my_printf("this is ELDEN RING\n");
    } else {
        my_printf("To launch the game, enter \"./my_rpg\"\n");
        my_printf("For the game rules, enter the option -h\n");
    }
}

int main(int ac, const char **av)
{
    sfTexture *texture = sfTexture_createFromFile("res/enemies/Spawn.png", 0);

    if (ac > 2 || texture == NULL) {
        option(0);
        return 84;
    }
    if (ac == 1 || (ac == 2 && av[1][0] == '-' && av[1][1] == 'f')) {
        srand(time(NULL));
        launcher(ac == 2 && av[1][0] == '-' && av[1][1] == 'f');
        return 0;
    }
    if (my_strlen(av[1]) == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h') {
            option(1);
            return 0;
        }
    }
    option(0);
    return 84;
}
