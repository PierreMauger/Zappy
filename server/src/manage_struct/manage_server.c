/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "server.h"

server_t *server_create(int port, size_t cli_per_team, size_t team_nbr)
{
    server_t *server = calloc(1, sizeof(server_t));

    if (server == NULL)
        return NULL;
    server->port = port;
    server->socket = nlib_create_socket();
    if (server->socket == NULL ||
        nlib_init_socket(server->socket, port,
            cli_per_team * team_nbr) == NULL)
        return NULL;
    server->clients = list_create();
    server->commands_to_send = list_create();
    if (server->clients == NULL || server->commands_to_send == NULL)
        return NULL;
    return server;
}

void server_destroy(server_t *server)
{
    if (server == NULL)
        return;
    if (server->socket)
        nlib_destroy_socket(server->socket);
    if (server->clients)
        list_destroy(server->clients, (void (*)(void *))client_destroy);
    if (server->commands_to_send)
        list_destroy(server->commands_to_send,
            (void (*)(void *))nlib_command_destroy);
    free(server);
}
