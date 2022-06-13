/*
** EPITECH PROJECT, 2022
** if_forest.c
** File description:
** if_forest ai
*/

#include "zappy_ai.h"

bool ai(client_t *client)
{
    if (!send_message(
        client->pending_commands, client->command, client->socket, "Forward")) {
        fprintf(stderr, "%s[ERROR]%s Malloc error send_message", R, W);
        return false;
    }
    return true;
}
