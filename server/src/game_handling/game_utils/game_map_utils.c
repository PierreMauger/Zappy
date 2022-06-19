/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

static pos_t **game_fill_map_dup(map_t *map, pos_t **pos)
{
    size_t x = 0;
    size_t y = 0;

    for (size_t i = 0; i < map->height * map->width; i++) {
        pos[i]->x = x;
        pos[i]->y = y;
        if (x == map->width - 1) {
            x = 0;
            y++;
        } else {
            x++;
        }
    }
    return pos;
}

void game_destroy_map_dup(map_t *map, pos_t **map_dup)
{
    for (size_t i = 0; i < map->height * map->width; i++)
        free(map_dup[i]);
    free(map_dup);
}

pos_t **game_reset_map_dup(map_t *map, pos_t **map_dup)
{
    return game_fill_map_dup(map, map_dup);
}

pos_t **game_init_map_dup(map_t *map)
{
    pos_t **pos = calloc(map->height * map->width, sizeof(pos_t *));

    if (pos == NULL)
        return NULL;
    for (size_t i = 0; i < map->height * map->width; i++) {
        pos[i] = calloc(1, sizeof(pos_t));
        if (pos[i] == NULL)
            return NULL;
    }
    return game_fill_map_dup(map, pos);
}

void game_map_dup_delete_idx(pos_t **map_dup, int idx, size_t remaining_tiles)
{
    pos_t *temp = map_dup[idx];

    map_dup[idx] = map_dup[remaining_tiles - 1];
    map_dup[remaining_tiles - 1] = temp;
}
