/*
** EPITECH PROJECT, 2022
** if_forest.c
** File description:
** if_forest ai
*/

#include "zappy_ai.h"

bool find_path_object(client_t *client)
{
    size_t y = client->player->pos.y;
    size_t x = client->player->pos.x;
    size_t nb_food = client->map[y][x].inv->food;

    //while (client->map[y][x].inv->food == 0) {
    //    //path_finding();
    //}
    if (nb_food == 0)
        return false;
    while (nb_food != 0 && client->pending_commands->lenght < 10) {
        if (!send_message(client->pending_commands,
            client->command, client->socket, "Take food\n")) {
            fprintf(stderr, "%s[ERROR]%s Malloc error send_message", R, W);
            return false;
        }
        nb_food--;
    }
    return true;
}

bool ai(client_t *client)
{
    if (!send_message(client->pending_commands,
        client->command, client->socket, "Look\n")) {
        fprintf(stderr, "%s[ERROR]%s Malloc error send_message", R, W);
        return false;
    }
    if (!send_message(client->pending_commands,
        client->command, client->socket, "Inventory\n")) {
        fprintf(stderr, "%s[ERROR]%s Malloc error send_message", R, W);
        return false;
    }
    if (client->player->inv && client->player->inv->food < 5) {
        if (!find_path_object(client))
            return true;
    }
    return true;
}
