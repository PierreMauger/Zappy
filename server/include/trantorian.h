/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** include
*/

#ifndef TRANTORIAN_H
    #define TRANTORIAN_H

    #include <uuid/uuid.h>

    #include <stdio.h>
    #include <stdlib.h>

    #include "inventory.h"

typedef struct {
    uuid_t id_team;
    size_t x;
    size_t y;
    inventory_t *inventory;
    size_t level;
} trantorian_t;

trantorian_t *trantorian_create(uuid_t id_team, size_t x, size_t y);
void trantorian_destroy(trantorian_t *trantorian);

#endif // TRANTORIAN_H
