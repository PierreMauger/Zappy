/*
** EPITECH PROJECT, 2022
** stdin.c
** File description:
** stdin ai
*/

#include "zappy_ai.h"

bool send_message_comm_false(client_t *client, char *com)
{
    if (client->pending_commands->lenght < 10 && !send_message(
        client->pending_commands, client->command, client->socket, com)) {
        fprintf(stderr, "%s[ERROR]%s Malloc error send_message", R, W);
        return false;
    }
    return false;
}

bool send_message_comm(client_t *client, char *com)
{
    if (!send_message(
        client->pending_commands, client->command, client->socket, com)) {
        fprintf(stderr, "%s[ERROR]%s Malloc error send_message", R, W);
        return false;
    }
    return true;
}

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

    if (client->map[y][x].player->lenght > 0)
        free(list_pop_last(client->map[y][x].player));
    print_inventory_map(client);
    return 0;
}
