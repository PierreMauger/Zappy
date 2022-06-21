/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** include
*/

#ifndef TRANTORIAN_H
    #define TRANTORIAN_H

    #define TRANT_INIT_FOOD 10
    #define TRANT_LIVE_IT 126

    #define TRANT_ANGLE 37

    #define IDX 1

    #include <uuid/uuid.h>

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>

    #include "inventory.h"
    #include "team.h"
    #include "client.h"
    #include "utils.h"

typedef enum {
    DIR_UP,
    DIR_RIGHT,
    DIR_DOWN,
    DIR_LEFT,

    DIR_SIZE
} direction_e;

typedef enum {
    TILE_ONE = 1,
    TILE_THREE = 3,
    TILE_FIVE = 5,
    TILE_SEVEN = 7,

    TILE_TWO = 2,
    TILE_FOUR = 4,
    TILE_SIX = 6,
    TILE_EIGHT = 8,

    TILE_ZERO,
    TILE_NONE = 0,
} dir_tile_e;

typedef enum {
    TRANT_HATCHING,
    TRANT_LIVING,
    TRANT_DEAD,
} trant_state_e;

struct client_s;

typedef struct trantorian_s {
    char *uuid;
    team_t *team;
    struct client_s *client;
    trant_state_e state;
    size_t live_it;
    inventory_t *inventory;
    size_t level;
    pos_t pos;
    direction_e direction;
} trantorian_t;

trantorian_t *trantorian_create(team_t *team, size_t map_x, size_t map_y,
    bool rand_pos);
void trantorian_destroy(trantorian_t *trantorian);

typedef struct {
    direction_e direction;
    int coef_1;
    int coef_2;
    bool invert;
} dir_to_coef_t;

#endif // TRANTORIAN_H
