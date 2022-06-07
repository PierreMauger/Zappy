/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "trantorian.h"

trantorian_t *trantorian_create(uuid_t id_team, size_t x, size_t y)
{
    trantorian_t *trantorian = calloc(1, sizeof(trantorian_t));

    if (!trantorian)
        return NULL;
    uuid_copy(trantorian->id_team, id_team);
    trantorian->x = x;
    trantorian->y = y;
    trantorian->inventory = inventory_create();
    if (!trantorian->inventory) {
        free(trantorian);
        return NULL;
    }
    trantorian->level = 1;
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
