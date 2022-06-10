/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** include
*/

#ifndef SERVER_H
    #define SERVER_H

    #include <stdio.h>

    #include "list.h"
    #include "nlib.h"

    #include "client.h"

typedef struct {
    int fd;
    char *buffer;
} request_t;

request_t *request_create(int fd, char *buffer);
void request_destroy(request_t *request);

typedef struct {
    int port;
    socket_t *socket;
    list_t *clients;
    list_t *commands;
} server_t;

server_t *server_create(int port, size_t cli_per_team, size_t team_nbr);
void server_destroy(server_t *server);

#endif // SERVER_H
