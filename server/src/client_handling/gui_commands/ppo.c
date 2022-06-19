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
    char *uuid = strtok(command, " \t#");
    char *temp = NULL;

    if (uuid == NULL || strcmp(uuid, client->trantorian->uuid) != 0) {
        fprintf(stderr, "[ERROR] GUI unknown parameter\n");
        command_sbp(core, client);
        return;
    }
    if (asprintf(&temp, "ppo %s %ld %ld %d\n", uuid,
            client->trantorian->pos.x, client->trantorian->pos.y,
            (int)client->trantorian->direction) == -1) {
        fprintf(stderr, "[ERROR] GUI Can't malloc\n");
        command_suc(core, client);
        return;
    }
    client_push_command(core->server, client, temp);
}
