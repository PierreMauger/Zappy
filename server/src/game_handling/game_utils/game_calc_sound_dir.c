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

static dir_tile_e game_get_dir_tile(direction_e dir, size_t angle,
    size_t first_dec, size_t second_dec)
{
    if (angle < 18) {
        return unpair_dir_tile[(dir + first_dec) % 4];
    } else if (angle >= 18 && angle < 71) {
        return pair_dir_tile[(dir + second_dec) % 4];
    } else if (angle >= 71 && angle <= 90) {
        return unpair_dir_tile[(dir + second_dec) % 4];
    }
    return TILE_NONE;
}

static dir_tile_e game_get_dir_tile_from_angle(direction_e dir,
    vector_t *vector, size_t angle)
{
    if (vector->x > 0 && vector->y < 0) {
        return game_get_dir_tile(dir, angle, 0, 3);
    }
    if (vector->x > 0 && vector->y > 0) {
        return game_get_dir_tile(dir, angle, 3, 2);
    }
    if (vector->x < 0 && vector->y > 0) {
        return game_get_dir_tile(dir, angle, 1, 2);
    }
    if (vector->x < 0 && vector->y < 0) {
        return game_get_dir_tile(dir, angle, 1, 0);
    }
    return TILE_NONE;
}

static dir_tile_e handle_axis(direction_e dir, vector_t *vector, size_t angle)
{
    if (vector->x == 0 && vector->y > 0) {
        return game_get_dir_tile(dir, angle, 1, 0);
    }
    if (vector->x == 0 && vector->y < 0) {
        return game_get_dir_tile(dir, angle, 1, 2);
    }
    if (vector->x > 0 && vector->y == 0) {
        return game_get_dir_tile(dir, angle, 3, 2);
    }
    if (vector->x < 0 && vector->y == 0) {
        return game_get_dir_tile(dir, angle, 1, 0);
    }
    return TILE_NONE;
}

dir_tile_e game_calc_direction(map_t *map, direction_e dir, pos_t *a,
    pos_t *b)
{
    vector_t *vector = NULL;
    dir_tile_e res = TILE_NONE;
    size_t angle = 0;

    vector = game_calc_vector(map->width, map->height, a, b);
    if (vector == NULL) {
        fprintf(stderr, "[ERROR] Failed to calculate vector\n");
        return TILE_NONE;
    }
    if (vector->x == 0 && vector->y == 0) {
        free(vector);
        return TILE_ZERO;
    }
    angle = game_calc_angle_degrees(vector);
    if (vector->x == 0 || vector->y == 0) {
        res = handle_axis(dir, vector, angle);
    } else {
        res = game_get_dir_tile_from_angle(dir, vector, angle);
    }
    free(vector);
    return res;
}
