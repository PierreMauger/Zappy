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

static bool spl_scan_paths(client_t *client, pps_t *x_y, pos_t sx, char *obj)
{
    size_t n = client->player->level;

    if (string_to_number_object(client->map[round_map(client, sx.y + n, 0)]
        [round_map(client, sx.x + n, 1)], obj) > 0) {
        *x_y->y = round_map(client, sx.y + n, 0);
        *x_y->x = round_map(client, sx.x + n, 1);
        return true;
    }
    if (string_to_number_object(client->map[round_map(client, sx.y - n, 0)]
        [round_map(client, sx.x - n, 1)], obj) > 0) {
        *x_y->x = round_map(client, sx.x - n, 1);
        *x_y->y = round_map(client, sx.y - n, 0);
        return true;
    }
    if (string_to_number_object(client->map[round_map(client, sx.y - n, 0)]
        [round_map(client, sx.x + n, 1)], obj) > 0) {
        *x_y->y = round_map(client, sx.y - n, 0);
        *x_y->x = round_map(client, sx.x + n, 1);
        return true;
    }
    return false;
}

static bool spl_scan_path(client_t *client, pps_t *x_y, pos_t sx_sy, char *obj)
{
    size_t n = client->player->level;

    if (string_to_number_object(client->map[round_map(client, sx_sy.y + n, 0)]
        [round_map(client, sx_sy.x, 1)], obj) > 0) {
        *x_y->y = round_map(client, sx_sy.y + n, 0);
        return true;
    }
    if (string_to_number_object(client->map[round_map(client, sx_sy.y, 0)]
        [round_map(client, sx_sy.x + n, 1)], obj) > 0) {
        *x_y->x = round_map(client, sx_sy.x + n, 1);
        return true;
    }
    if (string_to_number_object(client->map[round_map(client, sx_sy.y - n, 0)]
        [round_map(client, sx_sy.x, 1)], obj) > 0) {
        *x_y->y = round_map(client, sx_sy.y - n, 0);
        return true;
    }
    if (string_to_number_object(client->map[round_map(client, sx_sy.y, 0)]
        [round_map(client, sx_sy.x - n, 1)], obj) > 0) {
        *x_y->x = round_map(client, sx_sy.x - n, 1);
        return true;
    }
    return false;
}

bool scan_path_finding(client_t *client, size_t *x, size_t *y, char *obj)
{
    size_t s_x = *x;
    size_t s_y = *y;
    pps_t x_y = {(int *)x, (int *)y};
    pos_t sx_sy = {s_x, s_y};
    size_t size = ((client->size_map.x > client->size_map.y)
        ? client->size_map.x : client->size_map.y);

    while (client->player->level < (size / 2)) {
        if (spl_scan_path(client, &x_y, sx_sy, obj)
            || spl_scan_paths(client, &x_y, sx_sy, obj))
            break;
        if (string_to_number_object(client->map[round_map(
            client, s_y + client->player->level, 0)]
            [round_map(client, s_x - client->player->level, 1)], obj) > 0) {
            *x = round_map(client, s_x - client->player->level, 1);
            *y = round_map(client, s_y + client->player->level, 0);
            break;
        }
        client->player->level++;
    }
    if (client->player->level == (size / 2))
        return false;
    return true;
}

bool path_finding_object(client_t *client, char *object)
{
    size_t x = client->player->pos.x;
    size_t y = client->player->pos.y;
    size_t save = client->player->level;

    if (string_to_number_object(client->map[x][y], object) != 0)
        return true;
    client->player->level = 1;
    if (!scan_path_finding(client, &x, &y, object)) {
        client->player->level = save;
        return false;
    }
    client->player->level = save;
    printf("GO NEXT OBJ %ld %ld\n", x, y);
    if (!go_to_next_object(client, x, y)) {
        return false;
    }
    return true;
}
