/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** include
*/

#ifndef ZAPPY_AI_H
    #define ZAPPY_AI_H

    #ifndef _GNU_SOURCE
        #define _GNU_SOURCE
    #endif

    #define SUCCESS (0)
    #define ERROR (1)
    #define EXIT (2)

    #define ERROR_EXIT (84)

    #define UNUSED __attribute__((unused))

    #include <sys/types.h>
    #include <linux/limits.h>
    #include <sys/stat.h>

    #include <errno.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include <stdbool.h>
    #include <regex.h>
    #include <fcntl.h>
    #include <signal.h>

    #include "list.h"
    #include "nlib.h"

typedef struct arg_s {
    int port;
    char *name;
    char *machine;
} arg_t;

typedef struct pos_s {
    int x;
    int y;
} pos_t;

typedef struct player_s {
    pos_t pos;
} player_t;

typedef struct client_s {
    socket_t *socket;
    char *team_name;
    char *machine;
    pos_t size_map;
    bool init;
    bool client_connected;
    fd_set readfds;
    fd_set writefds;
    list_t *command;
    player_t *player;
} client_t;

#define R "\033[1;31m"
#define G "\033[1;32m"
#define Y "\033[1;33m"
#define B "\033[1;34m"
#define M "\033[1;35m"
#define C "\033[1;36m"
#define W "\033[1;0m"

client_t *create_client(arg_t *arg);
void free_client(client_t *client);
bool init_client(arg_t *arg);

bool parse_return(client_t *client, char *str);

void sig_handler(int signum);

#endif // ZAPPY_AI_H
