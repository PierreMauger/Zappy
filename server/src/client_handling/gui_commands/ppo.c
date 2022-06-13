/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

void command_ppo(core_t *core, client_t *client, char *command)
{
    char *uuid = strtok(command, " \t");
    char *temp = NULL;

    if (uuid == NULL || strcmp(uuid, client->trantorian->uuid) != 0) {
        fprintf(stderr, "[ERROR] GUI unknown parameter\n");
        client_push_command(core->server, client, strdup("sbp\n"));
        return;
    }
    if (asprintf(&temp, "ppo %s %d %ld %ld\n", uuid,
            (int)client->trantorian->direction,
            client->trantorian->x, client->trantorian->y) == -1) {
        fprintf(stderr, "[ERROR] GUI Can't malloc\n");
        client_push_command(core->server, client, strdup("suc\n"));
        return;
    }
    client_push_command(core->server, client, temp);
}
