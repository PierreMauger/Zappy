/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

static int get_x_y(char *command, size_t *x, size_t *y)
{
    char *tmp = strtok(command, " \t");

    for (size_t i = 0; i < 2; i++) {
        if (tmp == NULL)
            return ERROR;
        if (i == 0) {
            *x = atol(tmp);
        } else {
            *y = atol(tmp);
        }
        tmp = strtok(NULL, " \t");
    }
    return SUCCESS;
}

void command_write_tile_content(core_t *core, client_t *client,
    size_t x, size_t y)
{
    char *buffer = NULL;

    if (asprintf(&buffer, "bct %ld %ld %ld %ld %ld %ld %ld %ld %ld\n",
            x, y,
            core->game->map->map[y][x].food,
            core->game->map->map[y][x].linemate,
            core->game->map->map[y][x].deraumere,
            core->game->map->map[y][x].sibur,
            core->game->map->map[y][x].mendiane,
            core->game->map->map[y][x].phiras,
            core->game->map->map[y][x].thystame) == -1) {
        fprintf(stderr, "[ERROR] GUI Can't malloc\n");
        client_push_command(core->server, client, strdup("suc\n"));
    }
    client_push_command(core->server, client, buffer);
}

void command_bct(core_t *core, client_t *client, char *command)
{
    size_t x = 0;
    size_t y = 0;

    if (get_x_y(command, &x, &y) == ERROR) {
        fprintf(stderr, "[ERROR] GUI Bad params\n");
        client_push_command(core->server, client, strdup("sbp\n"));
        return;
    }
    command_write_tile_content(core, client, x, y);
}
