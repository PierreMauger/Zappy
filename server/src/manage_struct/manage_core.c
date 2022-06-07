/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "core.h"

core_t *core_create(void)
{
    return calloc(1, sizeof(core_t));
}

void core_destroy(core_t *core)
{
    if (core == NULL)
        return;
    if (core->game != NULL)
        game_destroy(core->game);
    if (core->server != NULL)
        server_destroy(core->server);
    free(core);
}
