/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "core.h"

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
