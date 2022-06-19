/*
** EPITECH PROJECT, 2022
** send_message.c
** File description:
** send_message ai
*/

#include "zappy_ai.h"

int round_map(client_t *client, int pos, bool is_x)
{
    if (is_x) {
        if (pos >= client->size_map.x)
            return pos - client->size_map.x;
        if (pos < 0)
            return pos + client->size_map.x;
        return pos;
    } else {
        if (pos >= client->size_map.y)
            return pos - client->size_map.y;
        if (pos < 0)
            return pos + client->size_map.y;
    }
    return pos;
}

void find_closest_round(client_t *client, size_t *dest_x, size_t *dest_y)
{
    size_t src_x = client->player->pos.x;
    size_t src_y = client->player->pos.y;

    if (*dest_x > src_x) {
        if (*dest_x - src_x > (client->size_map.x - *dest_x))
            *dest_x = client->size_map.x - *dest_x;
    }
    if (client->size_map.y - *dest_y < *dest_y)
        *dest_y = client->size_map.y - *dest_y;
}
