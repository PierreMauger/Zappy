/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "core.h"

int core_init(core_t *core, args_t *args)
{
    core->game = game_create(args->teams, args->width, args->height,
        args->cli_per_team);
    if (core->game == NULL) {
        core_destroy(core);
        return ERROR;
    }
    core->game->freq = args->freq;
    core->server = server_create(args->port, args->cli_per_team, args->freq);
    if (core->server == NULL) {
        core_destroy(core);
        return ERROR;
    }
    return SUCCESS;
}

int server_start(args_t *args)
{
    core_t *core = core_create();

    if (core == NULL || core_init(core, args) == ERROR)
        return ERROR;
    printf("[INFO] Server listening on port %d\n", core->server->port);
    return server_loop(core);
}
