/*
** EPITECH PROJECT, 2022
** init_client.c
** File description:
** init_client ai
*/

#include "zappy_ai.h"

int string_to_number_object_in_inv(inventory_t inv, char *object_name)
{
    if (strcmp(object_name, "food") == 0)
        return inv.food;
    if (strcmp(object_name, "deraumere") == 0)
        return inv.deraumere;
    if (strcmp(object_name, "linemate") == 0)
        return inv.linemate;
    if (strcmp(object_name, "mendiane") == 0)
        return inv.mendiane;
    if (strcmp(object_name, "phiras") == 0)
        return inv.phiras;
    if (strcmp(object_name, "sibur") == 0)
        return inv.sibur;
    if (strcmp(object_name, "thystame") == 0)
        return inv.thystame;
    return 0;
}

int string_to_number_object(map_t map, char *object_name)
{
    if (strcmp(object_name, "food") == 0)
        return map.inv->food;
    if (strcmp(object_name, "deraumere") == 0)
        return map.inv->deraumere;
    if (strcmp(object_name, "linemate") == 0)
        return map.inv->linemate;
    if (strcmp(object_name, "mendiane") == 0)
        return map.inv->mendiane;
    if (strcmp(object_name, "phiras") == 0)
        return map.inv->phiras;
    if (strcmp(object_name, "sibur") == 0)
        return map.inv->sibur;
    if (strcmp(object_name, "thystame") == 0)
        return map.inv->thystame;
    return 0;
}

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
