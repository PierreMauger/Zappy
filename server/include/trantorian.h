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
    #include "team.h"

typedef enum {
    DIR_UP,
    DIR_RIGHT,
    DIR_DOWN,
    DIR_LEFT,

    DIR_SIZE
} direction_e;

typedef struct {
    char *uuid;
    team_t *team;
    inventory_t *inventory;
    size_t level;
    size_t x;
    size_t y;
    direction_e direction;
} trantorian_t;

trantorian_t *trantorian_create(team_t *team, size_t map_x, size_t map_y);
void trantorian_destroy(trantorian_t *trantorian);

#endif // TRANTORIAN_H
