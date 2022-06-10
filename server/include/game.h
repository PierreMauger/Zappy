/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** include
*/

#ifndef GAME_H
    #define GAME_H

    #ifndef SUCCESS
        #define SUCCESS (0)
    #endif
    #ifndef ERROR
        #define ERROR (1)
    #endif
    #ifndef EXIT
        #define EXIT (2)
    #endif

    #include <stdio.h>

    #include "list.h"

    #include "map.h"
    #include "trantorian.h"
    #include "team.h"

typedef struct {
    size_t cli_per_team;
    list_t *teams;
    list_t *trantorians;
    map_t *map;
} game_t;

game_t *game_create(char **teams, size_t width, size_t height,
    size_t cli_per_team);
void game_destroy(game_t *game);

#endif // GAME_H
