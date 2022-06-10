/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "client.h"

client_t *client_create(int fd)
{
    client_t *client = calloc(1, sizeof(client_t));

    if (client == NULL)
        return NULL;
    client->sock = nlib_create_socket();
    if (client->sock == NULL)
        return NULL;
    client->sock->fd = fd;
    return client;
}

void client_destroy(client_t *client)
{
    if (client == NULL)
        return;
    if (client->sock != NULL)
        nlib_destroy_socket(client->sock);
    if (client->id_team != NULL)
        uuid_clear(client->id_team);
    free(client);
}
