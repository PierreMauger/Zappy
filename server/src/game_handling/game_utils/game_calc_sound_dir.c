/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

static const dir_tile_e dir_tiles[] = {
    TILE_ONE,
    TILE_TWO,
    TILE_THREE,
    TILE_FOUR,
    TILE_FIVE,
    TILE_SIX,
    TILE_SEVEN,
    TILE_EIGHT,
};

static dir_tile_e game_angle_to_tile(size_t angle, direction_e dir)
{
    size_t nb_tiles = sizeof(dir_tiles) / sizeof(dir_tile_e);
    size_t tile_angle = 360 / nb_tiles;
    size_t tile_index = (angle / tile_angle) + dir * 2;
    dir_tile_e tile;

    if (tile_index >= nb_tiles) {
        tile_index %= nb_tiles;
    }
    tile = dir_tiles[tile_index];
    return tile;
}

dir_tile_e game_calc_direction(map_t *map, direction_e dir, pos_t *a,
    pos_t *b)
{
    vector_t *vector = NULL;
    size_t angle = 0;
    pos_t origin = {0, 0};

    vector = game_calc_vector(map->width, map->height, a, b);
    if (vector == NULL) {
        fprintf(stderr, "[ERROR] Failed to calculate vector\n");
        return TILE_NONE;
    }
    if (vector->x == 0 && vector->y == 0) {
        free(vector);
        return TILE_ZERO;
    }
    angle = game_calc_angle_degrees(&origin, (pos_t *)vector);
    free(vector);
    return game_angle_to_tile(angle, dir);
}
