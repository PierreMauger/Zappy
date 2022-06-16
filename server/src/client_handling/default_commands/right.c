/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "core.h"

void right_e(core_t *core, client_t *client, UNUSED char *command)
{
    client->trantorian->direction++;
    if (client->trantorian->direction > 3)
        client->trantorian->direction = 0;
    client_push_command(core->server, client, strdup("ok\n"));
}

void command_right(core_t *core, client_t *client, UNUSED char *command)
{
    if (client == NULL || client->trantorian == NULL) {
        fprintf(stderr, "[ERROR] Invalid client\n");
        client_push_command(core->server, client, strdup("ko\n"));
        return;
    }
    client->handler->command = right_e;
    client->handler->command_it = 7;
}
