/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "core.h"

void take_e(UNUSED core_t *core, UNUSED client_t *client, UNUSED char *command)
{
    // TODO
}

void command_take(core_t *core, client_t *client, char *command)
{
    if (client == NULL || client->trantorian == NULL) {
        fprintf(stderr, "[ERROR] Invalid client\n");
        client_push_command(core->server, client, strdup("ko\n"));
        return;
    }
    client->handler->params = strdup(command);
    client->handler->command = take_e;
    client->handler->command_it = 7;
}
