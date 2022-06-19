/*
** EPITECH PROJECT, 2022
** init_client.c
** File description:
** init_client ai
*/

#include "zappy_ai.h"

void free_map_copy(map_t **map, size_t x, size_t y)
{
    size_t max_x = x;
    size_t max_y = y;

    for (size_t y = 0; y < max_y; y++) {
        for (size_t x = 0; x < max_x; x++)
            free(map[y][x].inv);
        free(map[y]);
    }
    free(map);
}

static void copy_inv_map(inventory_t *inventory, inventory_t *cp_inventory)
{
    cp_inventory->food = inventory->food;
    cp_inventory->deraumere = inventory->deraumere;
    cp_inventory->linemate = inventory->linemate;
    cp_inventory->mendiane = inventory->mendiane;
    cp_inventory->phiras = inventory->phiras;
    cp_inventory->sibur = inventory->sibur;
    cp_inventory->thystame = inventory->thystame;
}

static bool split_create_map(map_t *new_map, map_t *map, size_t x)
{
    size_t i = 0;

    for (i = 0; i != x; i++) {
        new_map[i].inv = calloc(1, sizeof(inventory_t));
        if (!new_map[i].inv)
            return false;
        copy_inv_map(map[i].inv, new_map[i].inv);
        new_map[i].player = map[i].player;
    }
    new_map[i].player = NULL;
    new_map[i].inv = NULL;
    return true;
}

map_t **copy_double_tab(map_t **map, size_t x, size_t y)
{
    size_t h = 0;
    map_t **new_map = malloc(sizeof(map_t *) * (y + 1));

    if (!new_map)
        return NULL;
    for (h = 0; h != y; h++) {
        new_map[h] = malloc(sizeof(map_t) * (x + 1));
        if (!new_map[h])
            return NULL;
        if (!split_create_map(new_map[h], map[h], x))
            return NULL;
    }
    new_map[h] = NULL;
    return new_map;
}
