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
} response_t;

response_t *response_create(int fd, char *buffer);
void response_destroy(response_t *response);

typedef struct {
    int port;
    socket_t *socket;
    size_t max_client;
    list_t *clients;
    list_t *reponses;
} server_t;

server_t *server_create(int port, size_t max_client, size_t team_nbr);
void server_destroy(server_t *server);

#endif // SERVER_H
