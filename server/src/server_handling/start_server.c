/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "core.h"

int server_start(args_t *args)
{
    core_t *core = core_create();

    if (core == NULL)
        return ERROR;
    core->game = game_create(args->teams, args->width, args->height,
        args->cli_per_team);
    if (core->game == NULL) {
        core_destroy(core);
        return ERROR;
    }
    core->server = server_create(args->port, args->cli_per_team, args->freq);
    if (core->server == NULL) {
        core_destroy(core);
        return ERROR;
    }
    printf("[INFO] Server listening on port %d\n", core->server->port);
    return server_loop(core);
}
