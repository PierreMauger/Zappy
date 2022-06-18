/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

void game_remove_trantorian(core_t *core, trantorian_t *trantorian)
{
    list_destroy_data_node(core->server->clients, trantorian->client,
        (void (*)(void *))client_destroy);
    list_destroy_data_node(core->game->trantorians, trantorian,
        (void (*)(void *))trantorian_destroy);
}

team_t *team_get_obj(list_t *teams, const char *to_comp)
{
    node_t *node = NULL;
    team_t *team = NULL;

    foreach(teams->head, node) {
        team = (team_t *)node->data;
        if (strcmp(team->name, to_comp) == 0)
            return team;
    }
    return NULL;
}

static ssize_t game_calc_shortest_coord(size_t map_edge, size_t coord_a,
    size_t coord_b)
{
    ssize_t pos = 0;
    ssize_t neg = 0;

    pos = coord_a - coord_b;
    if (coord_a > coord_b) {
        coord_b += map_edge;
    } else if (coord_a < coord_b) {
        coord_a += map_edge;
    }
    neg = coord_a - coord_b;
    if (llabs(pos) < llabs(neg))
        return pos;
    return neg;
}

vector_t *game_calc_vector_norm(size_t map_x, size_t map_y,
    pos_t *a, pos_t *b)
{
    vector_t *res = malloc(sizeof(vector_t));

    if (res == NULL)
        return NULL;
    res->x = game_calc_shortest_coord(map_x, a->x, b->x);
    res->y = game_calc_shortest_coord(map_y, a->y, b->y);
    return res;
}
