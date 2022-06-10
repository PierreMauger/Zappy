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

    #ifndef SUCCESS
        #define SUCCESS (0)
    #endif
    #ifndef ERROR
        #define ERROR (1)
    #endif
    #ifndef EXIT
        #define EXIT (2)
    #endif

    #define ERROR_EXIT (84)

    #define UNUSED __attribute__((unused))

    #define DEFAULT_PORT (8080)
    #define DEFAULT_WIDTH (10)
    #define DEFAULT_HEIGHT (10)
    #define DEFAULT_FREQ (100)

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>

    #include "list.h"
    #include "nlib.h"

    #include "server.h"
    #include "game.h"

typedef struct {
    int port;
    size_t width;
    size_t height;
    size_t cli_per_team;
    size_t freq;
    char **teams;
} args_t;

typedef struct {
    server_t *server;
    game_t *game;
} core_t;

core_t *core_create(void);
void core_destroy(core_t *core);

args_t *init_args(void);
void destroy_args(args_t *args);

int verif_params(args_t *args);
int parse_params(int argc, char **argv, args_t *args);

void set_read_fds(server_t *serv, fd_set *fds);
void set_write_fds(server_t *serv, fd_set *fds);

int server_start(args_t *args);
int server_loop(core_t *core);

#endif // CORE_H
