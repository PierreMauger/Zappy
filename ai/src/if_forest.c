/*
** EPITECH PROJECT, 2022
** if_forest.c
** File description:
** if_forest ai
*/

#include "zappy_ai.h"

bool get_food_in_cell(client_t *client, size_t x, size_t y)
{
    size_t nb_food = client->map[y][x].inv->food;

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

bool try_evoluate(client_t *client)
{
    return true;
}

bool remove_surplus_command(client_t *client)
{
    while (client->pending_commands->lenght > 10)
        free(list_pop_last(client->pending_commands));
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
        if (!path_finding_object(client, "food") && !send_message(client->
            pending_commands, client->command, client->socket, "Forward\n")) {
            fprintf(stderr, "%s[ERROR]%s Malloc error send_message", R, W);
            return false;
        }
    }
    else
        try_evoluate(client);
    return remove_surplus_command(client);
}
