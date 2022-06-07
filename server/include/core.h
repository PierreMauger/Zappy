/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** include
*/

#ifndef CORE_H
    #define CORE_H

    #ifndef _GNU_SOURCE
        #define _GNU_SOURCE
    #endif

    #define SUCCESS (0)
    #define ERROR (1)
    #define EXIT (2)

    #define ERROR_EXIT (84)

    #define UNUSED __attribute__((unused))

    #include <stdio.h>

    #include "list.h"
    #include "nlib.h"

    #include "server.h"
    #include "game.h"

typedef struct {
    server_t *server;
    game_t *game;
} core_t;

core_t *core_create(void);
void core_destroy(core_t *core);

#endif // CORE_H
