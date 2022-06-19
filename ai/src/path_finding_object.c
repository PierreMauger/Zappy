/*
** EPITECH PROJECT, 2022
** init_client.c
** File description:
** init_client ai
*/

#include "zappy_ai.h"

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

bool recursive_path_finding(map_t **map, size_t *x, size_t *y, char *obj)
{
    if (string_to_number_object(map[*x][*y], obj) > 0)
        return true;
    if (string_to_number_object(map[*x][*y], obj) == -1)
        return false;
    return true;
}

bool path_finding_object(client_t *client, char *object)
{
    size_t x = client->player->pos.x;
    size_t y = client->player->pos.y;
    map_t **map = copy_double_tab(client->map,
        client->size_map.x, client->size_map.y);

    if (!recursive_path_finding(map, &x, &y, object)) {
        free_map_copy(map, client->size_map.x, client->size_map.y);
        return false;
    }
    if (!go_to_next_object(client, x, y)) {
        free_map_copy(map, client->size_map.x, client->size_map.y);
        return false;
    }
    free_map_copy(map, client->size_map.x, client->size_map.y);
    return true;
}
