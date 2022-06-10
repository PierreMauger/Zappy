/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** include
*/

#ifndef CORE_H
    #define CORE_H

    #define DEFAULT_PORT (8080)
    #define DEFAULT_WIDTH (10)
    #define DEFAULT_HEIGHT (10)
    #define DEFAULT_FREQ (100)

    #define ERROR_EXIT (84)

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>

    #include "list.h"
    #include "nlib.h"

    #include "server.h"
    #include "game.h"
    #include "utils.h"

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
