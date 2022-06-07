/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "server.h"

response_t *create_response(int fd, char *buffer)
{
    response_t *response = calloc(1, sizeof(response_t));

    if (response == NULL)
        return NULL;
    response->fd = fd;
    response->buffer = buffer;
    return response;
}

void destroy_response(response_t *response)
{
    if (response == NULL)
        return;
    if (response->buffer != NULL)
        free(response->buffer);
    free(response);
}

server_t *server_create(int port, size_t max_client, size_t team_nbr)
{
    server_t *server = calloc(1, sizeof(server_t));

    if (server == NULL)
        return NULL;
    server->port = port;
    server->socket = nlib_create_socket();
    if (server->socket == NULL ||
        nlib_init_socket(server->socket, port, team_nbr) == NULL)
        return NULL;
    server->max_client = max_client;
    server->clients = list_create();
    server->reponses = list_create();
    if (server->clients == NULL || server->reponses == NULL)
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
    if (server->reponses)
        list_destroy(server->reponses, (void (*)(void *))free);
    free(server);
}
