/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

void command_plv(core_t *core, client_t *client, char *command)
{
    char *uuid = strtok(command, " \t");
    char *temp = NULL;

    if (uuid == NULL || strcmp(uuid, client->trantorian->uuid) != 0) {
        fprintf(stderr, "[ERROR] GUI unknown parameter\n");
        command_sbp(core, client);
        return;
    }
    if (asprintf(&temp, "plv %s %ld\n", uuid,
            client->trantorian->level) == -1) {
        fprintf(stderr, "[ERROR] GUI Can't malloc\n");
        command_suc(core, client);
        return;
    }
    client_push_command(core->server, client, temp);
}
