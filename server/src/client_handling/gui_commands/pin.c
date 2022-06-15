/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

static char *command_pin_get_buff(core_t *core, client_t *client, char *uuid)
{
    char *buff = NULL;

    if (asprintf(&buff, "pin %s %ld %ld %ld %ld %ld %ld %ld %ld %ld\n", uuid,
            core->game->map->width, core->game->map->height,
            client->trantorian->inventory->food,
            client->trantorian->inventory->linemate,
            client->trantorian->inventory->deraumere,
            client->trantorian->inventory->sibur,
            client->trantorian->inventory->mendiane,
            client->trantorian->inventory->phiras,
            client->trantorian->inventory->thystame) == -1)
        return NULL;
    return buff;
}

void command_pin(core_t *core, client_t *client, char *command)
{
    char *uuid = strtok(command, " \t");
    char *buff = NULL;

    if (uuid == NULL || strcmp(uuid, client->trantorian->uuid) != 0) {
        fprintf(stderr, "[ERROR] GUI unknown parameter\n");
        command_sbp(core, client);
        return;
    }
    buff = command_pin_get_buff(core, client, uuid);
    if (buff == NULL) {
        fprintf(stderr, "[ERROR] GUI Can't malloc\n");
        command_suc(core, client);
        return;
    }
    client_push_command(core->server, client, buff);
}
