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

typedef enum {
    DIR_UP,
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT
} direction_e;

typedef struct {
    uuid_t id_team;
    inventory_t *inventory;
    size_t level;
    size_t x;
    size_t y;
    direction_e direction;
} trantorian_t;

trantorian_t *trantorian_create(uuid_t id_team, size_t x, size_t y);
void trantorian_destroy(trantorian_t *trantorian);

#endif // TRANTORIAN_H
