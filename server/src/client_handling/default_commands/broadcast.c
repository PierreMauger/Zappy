/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

static char *get_msg(char *command)
{
    for (size_t i = 0; i < strlen(command); i++) {
        if (command[i] != ' ') {
            return &command[i + 1];
        }
    }
    return NULL;
}

void broadcast_e(core_t *core, client_t *client, char *command)
{
    char *msg = get_msg(command);
    char *broad = NULL;

    if (msg == NULL) {
        fprintf(stderr, "[ERROR] Invalid broadcast text\n");
        return;
    }
    if (asprintf(&broad, "mesage %ld %ld, %s\n",
            client->trantorian->pos.x,
            client->trantorian->pos.y,
            msg) == -1) {
        fprintf(stderr, "[ERROR] Failed to malloc text\n");
        return;
    }
    client->type = CLI_UNKNOWN;
    client_def_broadcast_command(core->server, broad);
    client->type = CLI_DEFAULT;
    client_push_command(core->server, client, strdup("ok\n"));
}

void command_broadcast(core_t *core, client_t *client, char *command)
{
    if (client == NULL || client->trantorian == NULL) {
        fprintf(stderr, "[ERROR] Invalid client\n");
        client_push_command(core->server, client, strdup("ko\n"));
        return;
    }
    client->handler->params = strdup(command);
    client->handler->command = broadcast_e;
    client->handler->command_it = 7;
}
