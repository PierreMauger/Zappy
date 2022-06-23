/*
** EPITECH PROJECT, 2022
** if_forest.c
** File description:
** if_forest ai
*/

#include "zappy_ai.h"

bool basic_command(client_t *client)
{
    if (!send_message(client->pending_commands,
        client->command, client->socket, "Look\n")) {
        fprintf(stderr, "%s[ERROR]%s Malloc error send_message\n", R, W);
        return false;
    }
    if (!send_message(client->pending_commands,
        client->command, client->socket, "Inventory\n")) {
        fprintf(stderr, "%s[ERROR]%s Malloc error send_message\n", R, W);
        return false;
    }
    if (client->unused_slot == 0 && !send_message(client->pending_commands,
        client->command, client->socket, "Fork\n")) {
        fprintf(stderr, "%s[ERROR]%s Malloc error send_message\n", R, W);
        return false;
    }
    return true;
}
