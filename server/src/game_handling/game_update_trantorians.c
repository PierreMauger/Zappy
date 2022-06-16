/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "core.h"

void game_update_trantorians(core_t *core)
{
    node_t *node = NULL;
    trantorian_t *trantorian = NULL;

    foreach(core->game->trantorians->head, node) {
        trantorian = (trantorian_t *)node->data;
        // game_update_trantorian((trantorian_t *)node->data);

        if (trantorian->live_it > 0) {
            trantorian->live_it--;
        } else if (trantorian->inventory->food > 0) {
            trantorian->inventory->food--;
            trantorian->live_it = 126;
        } else {
            command_pdi(core, trantorian);
            command_death(core, trantorian->client, NULL);
            list_destroy_data_node(core->server->clients, trantorian->client,
                (void (*)(void *))client_destroy);
        }
    }
}
