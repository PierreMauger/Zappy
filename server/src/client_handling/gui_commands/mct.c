/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

void command_mct(core_t *core, client_t *client, UNUSED char *command)
{
    for (size_t i = 0; i < core->game->map->height; i++) {
        for (size_t j = 0; j < core->game->map->width; j++) {
            command_write_tile_content(core, client, j, i);
        }
    }
}
