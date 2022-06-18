/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

static const dir_tile_e unpair_dir_tile[] = {
    TILE_ONE,
    TILE_THREE,
    TILE_FIVE,
    TILE_SEVEN,
};

static const dir_tile_e pair_dir_tile[] = {
    TILE_TWO,
    TILE_FOUR,
    TILE_SIX,
    TILE_EIGHT,
};

// static const ra dir[] = {
//     {3}
// }

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

vector_t *game_calc_vector(size_t map_x, size_t map_y,
    pos_t *a, pos_t *b)
{
    vector_t *res = malloc(sizeof(vector_t));

    if (res == NULL)
        return NULL;
    res->x = game_calc_shortest_coord(map_x, a->x, b->x);
    res->y = game_calc_shortest_coord(map_y, a->y, b->y);
    return res;
}

size_t game_calc_angle_degrees(vector_t *vector)
{
    long double res = 0;

    res = atanl((long double)llabs(vector->y) / (long double)llabs(vector->x));
    res /= (M_PI * 2);
    res *= 360;
    // return 180 - ((size_t)res + 90);
    return (size_t)res;
}

dir_tile_e game_calc_direction(map_t *map, direction_e dir, pos_t *a,
    pos_t *b)
{
    vector_t *vector = NULL;
    size_t angle = 0;

    vector = game_calc_vector(map->width, map->height, a, b);
    if (vector == NULL) {
        fprintf(stderr, "[ERROR] Failed to calculate vector\n");
        return TILE_NONE;
    }
    angle = game_calc_angle_degrees(vector);
    if (vector->x >= 0 && vector->y >= 0) {
        // UP RIGHT
        if (angle < 18) {
            // 0
            return unpair_dir_tile[(dir + 0) % 4];
        } else if (angle >= 18 && angle < 71) {
            // 3
            return pair_dir_tile[(dir + 3) % 4];
        } else if (angle >= 71 && angle < 90) {
            // 3
            return unpair_dir_tile[(dir + 3) % 4];
        }
    }
    if (vector->x >= 0 && vector->y <= 0) {
        // DOWN RIGHT
        if (angle < 18) {
            // 3
            return unpair_dir_tile[(dir + 3) % 4];
        } else if (angle >= 18 && angle < 71) {
            // 2
            return pair_dir_tile[(dir + 2) % 4];
        } else if (angle >= 71 && angle < 90) {
            // 2
            return unpair_dir_tile[(dir + 2) % 4];
        }
    }
    if (vector->x <= 0 && vector->y <= 0) {
        // DOWN LEFT
        if (angle < 18) {
            // 2
            return unpair_dir_tile[(dir + 2) % 4];
        } else if (angle >= 18 && angle < 71) {
            // 1
            return pair_dir_tile[(dir + 1) % 4];
        } else if (angle >= 71 && angle < 90) {
            // 1
            return unpair_dir_tile[(dir + 1) % 4];
        }
    }
    if (vector->x <= 0 && vector->y >= 0) {
        // UP LEFT
        if (angle < 18) {
            // 1
            return unpair_dir_tile[(dir + 1) % 4];
        } else if (angle >= 18 && angle < 71) {
            // 0
            return pair_dir_tile[(dir + 0) % 4];
        } else if (angle >= 71 && angle < 90) {
            // 0
            return unpair_dir_tile[(dir + 0) % 4];
        }
    }
    free(vector);
    return TILE_NONE;
}
