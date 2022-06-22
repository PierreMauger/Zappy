/*
** EPITECH PROJECT, 2022
** stdin.c
** File description:
** stdin ai
*/

#include "zappy_ai.h"

player_t *create_player()
{
    player_t *player = calloc(1, sizeof(player_t));

    if (!player) {
        fprintf(stderr, "%s[ERROR]%s Malloc error create_player\n", R, W);
        return NULL;
    }
    return player;
}

int remove_false_player(client_t *client)
{
    size_t x = client->player->pos.x;
    size_t y = client->player->pos.y;

    free(list_pop_last(client->map[y][x].player));
    print_inventory_map(client);
    return 0;
}