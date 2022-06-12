/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "client.h"

void client_destroy_command(char *command)
{
    if (command != NULL)
        free(command);
}

client_t *client_create(int fd)
{
    client_t *client = calloc(1, sizeof(client_t));

    if (client == NULL)
        return NULL;
    client->sock = nlib_create_socket();
    client->exec_commands = list_create();
    if (client->sock == NULL || client->exec_commands == NULL)
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
    if (client->exec_commands != NULL)
        list_destroy(client->exec_commands,
            (void (*)(void *))client_destroy_command);
    free(client);
}
