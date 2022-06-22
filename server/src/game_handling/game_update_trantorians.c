/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "core.h"

static void game_update_live(core_t *core, trantorian_t *trantorian)
{
    if (trantorian->state != TRANT_LIVING)
        return;
    if (trantorian->live_it > 0) {
        trantorian->live_it--;
    } else if (trantorian->inventory->food > 0) {
        trantorian->inventory->food--;
        trantorian->live_it = TRANT_LIVE_IT;
    } else {
        command_pdi(core, trantorian);
        command_death(core, trantorian->client, NULL);
        trantorian->client->trantorian = NULL;
        trantorian_replace(core, trantorian->team, trantorian);
    }
}

void game_update_trantorians(core_t *core)
{
    node_t *node = NULL;
    node_t *safe = NULL;
    trantorian_t *trantorian = NULL;

    foreach_safe(core->game->trantorians->head, node, safe) {
        trantorian = (trantorian_t *)node->data;
        game_update_live(core, trantorian);
    }
}
