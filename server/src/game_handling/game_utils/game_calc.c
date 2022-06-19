/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

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
    return (size_t)res;
}
    // return 180 - ((size_t)res + 90);
