/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "core.h"

bool game_clock_update(size_t freq)
{
    static double elapsed = 0;
    static struct timeval last = {0};
    struct timeval actual = {0};
    bool ret = false;

    gettimeofday(&actual, NULL);
    if (last.tv_sec != 0 || last.tv_usec != 0) {
        elapsed += (double)(actual.tv_sec - last.tv_sec) * 1000 +
            (double)(actual.tv_usec - last.tv_usec) / 1000;
        if (elapsed >= 1000 / freq)
            ret = true;
        while (elapsed >= 1000 / freq) {
            elapsed -= 1000 / freq;
        }
    }
    last = actual;
    return ret;
}

void game_update_trantorian(core_t *core, client_t *client)
{
    if (client->handler->command_it > 0) {
        client->handler->command_it--;
    } else if (client->handler->command != NULL) {
        client->handler->command(core, client, client->handler->params);
        handler_clear(client->handler);
    }
    if (client->trantorian->live_it > 0) {
        client->trantorian->live_it--;
    } else if (client->trantorian->inventory->food > 0) {
        client->trantorian->inventory->food--;
        client->trantorian->live_it = 126;
    } else {
        command_pdi(core, client->trantorian);
        command_death(core, client, NULL);
        list_destroy_data_node(core->server->clients, client,
            (void (*)(void *))client_destroy);
    }
}

void game_update_trantorians(core_t *core)
{
    node_t *node = NULL;
    node_t *safe = NULL;
    client_t *client = NULL;

    foreach_safe(core->server->clients->head, node, safe) {
        client = (client_t *)node->data;
        if (client->type == CLI_DEFAULT) {
            game_update_trantorian(core, client);
        }
    }
}

void game_update(core_t *core)
{
    // if (game_clock_update(core->game->freq)) {
    //     game_update_trantorians(core);
    //     // game_update_map(core->game->map);
    // }
}
