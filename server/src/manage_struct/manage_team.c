/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "team.h"

team_t *team_create(char *name)
{
    team_t *team = calloc(1, sizeof(team_t));

    if (team == NULL)
        return NULL;
    team->name = strdup(name);
    if (team->name == NULL)
        return NULL;
    uuid_generate(team->id);
    return team;
}

void team_destroy(team_t *team)
{
    if (team == NULL)
        return;
    if (team->name)
        free(team->name);
    free(team);
}
