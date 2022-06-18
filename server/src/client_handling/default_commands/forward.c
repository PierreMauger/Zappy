/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "core.h"

static size_t control_dir(size_t last_pos, size_t max_pos, bool incr)
{
    if (incr)
        return (last_pos + 1) % max_pos;
    return (last_pos + max_pos - 1) % max_pos;
}

void forward_e(core_t *core, client_t *client, UNUSED char *command)
{
    switch (client->trantorian->direction) {
        case DIR_UP:
            client->trantorian->pos.y = control_dir(client->trantorian->pos.y,
                core->game->map->height, false);
            break;
        case DIR_RIGHT:
            client->trantorian->pos.x = control_dir(client->trantorian->pos.x,
                core->game->map->width, true);
            break;
        case DIR_DOWN:
            client->trantorian->pos.y = control_dir(client->trantorian->pos.y,
                core->game->map->height, true);
            break;
        case DIR_LEFT:
            client->trantorian->pos.x = control_dir(client->trantorian->pos.x,
                core->game->map->width, false);
            break;
        default:
            return;
    }
    client_push_command(core->server, client, strdup("ok\n"));
}

void command_forward(core_t *core, client_t *client, UNUSED char *command)
{
    if (client == NULL || client->trantorian == NULL) {
        fprintf(stderr, "[ERROR] Invalid client\n");
        client_push_command(core->server, client, strdup("ko\n"));
        return;
    }
    client->handler->command = forward_e;
    client->handler->command_it = 7;
}
