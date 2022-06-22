/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

trantorian_t *trantorian_find_free(list_t *trantorians, team_t *team)
{
    node_t *node = NULL;
    trantorian_t *res = NULL;

    foreach(trantorians->head, node) {
        res = (trantorian_t *)node->data;
        if (res->team == team && res->state == TRANT_READY)
            return res;
    }
    return NULL;
}

int trantorian_replace(core_t *core, team_t *team, trantorian_t *trantorian)
{
    node_t *node = NULL;
    trantorian_t *to_replace = NULL;

    foreach(core->game->trantorians->head, node) {
        to_replace = (trantorian_t *)node->data;
        if (to_replace != trantorian)
            continue;
        trantorian_destroy(to_replace);
        to_replace = trantorian_create(team, core->game->map->width,
            core->game->map->height, true);
        if (to_replace == NULL) {
            fprintf(stderr, "[ERROR] Unable to create trantorian\n");
            return ERROR;
        }
        to_replace->state = TRANT_READY;
        node->data = to_replace;
        return SUCCESS;
    }
    return ERROR;
}
