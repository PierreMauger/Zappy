/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "core.h"

void command_add_client(command_t *command, client_t *client)
{
    if (list_push_data(command->socks, client->sock) == LIST_FAILURE)
        fprintf(stderr, "[ERROR] Cannot add client to command\n");
}

void command_add_all_clients(command_t *commands, list_t *clients)
{
    node_t *node = NULL;
    client_t *client = NULL;

    foreach(clients->head, node) {
        client = (client_t *)node->data;
        command_add_client(commands, client);
    }
}
