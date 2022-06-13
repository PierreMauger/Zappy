/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "trantorian.h"

trantorian_t *trantorian_create(team_t *team, size_t map_x, size_t map_y)
{
    trantorian_t *trantorian = calloc(1, sizeof(trantorian_t));

    if (!trantorian)
        return NULL;
    trantorian->team = team;
    trantorian->x = rand() % map_x;
    trantorian->y = rand() % map_y;
    trantorian->inventory = inventory_create();
    if (!trantorian->inventory) {
        free(trantorian);
        return NULL;
    }
    trantorian->level = 1;
    trantorian->direction = rand() % 4;
    return trantorian;
}

void trantorian_destroy(trantorian_t *trantorian)
{
    if (trantorian == NULL)
        return;
    if (trantorian->inventory)
        inventory_destroy(trantorian->inventory);
    free(trantorian);
}
