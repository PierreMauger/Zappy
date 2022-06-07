/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "client.h"

client_t *client_create(int fd, uuid_t id_team)
{
    client_t *client = calloc(1, sizeof(client_t));

    if (client == NULL)
        return (NULL);
    client->fd = fd;
    uuid_copy(client->id_team, id_team);
    return client;
}

void client_destroy(client_t *client)
{
    if (client == NULL)
        return;
    if (client->fd >= 0)
        close(client->fd);
    if (client->id_team != NULL)
        uuid_clear(client->id_team);
    free(client);
}
