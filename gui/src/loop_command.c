/*
** EPITECH PROJECT, 2022
** loop_command.c
** File description:
** loop_command gui
*/

#include "zappy_gui.h"

bool first_command(client_t *client)
{
    if (!send_message(
        client->pending_commands, client->command, client->socket, "msz\n")) {
        fprintf(stderr, "%s[ERROR]%s Malloc error send_message", R, W);
        return false;
    }
    return true;
}

bool loop_command(client_t *client)
{
    if (!send_message(
        client->pending_commands, client->command, client->socket, "mct\n")) {
        fprintf(stderr, "%s[ERROR]%s Malloc error send_message", R, W);
        return false;
    }
    if (!send_message(
        client->pending_commands, client->command, client->socket, "ppo\n")) {
        fprintf(stderr, "%s[ERROR]%s Malloc error send_message", R, W);
        return false;
    }
    return true;  
}