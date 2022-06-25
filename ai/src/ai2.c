/*
** EPITECH PROJECT, 2022
** if_forest.c
** File description:
** if_forest ai
*/

#include "zappy_ai.h"

bool get_food_basic(client_t *client)
{
    if (!path_finding_object(client, "food") && !send_message(client->
        pending_commands, client->command, client->socket, "Forward\n")) {
        fprintf(stderr, "%s[ERROR]%s Malloc error send_message\n", R, W);
        return false;
    }
    return true;
}

static bool go_to_broadcast_dir3(client_t *client, int x, size_t d)
{
    if (d == 3) {
        if (!go_to_good_direction_x(client, x - 1, client->player->pos.x))
            return false;
        if (!send_message(client->pending_commands,
            client->command, client->socket, "Forward\n")) {
            fprintf(stderr, "%s[ERROR]%s Malloc error send_message\n", R, W);
            return false;
        }
        return true;
    } else {
        if (!go_to_good_direction_x(client, x + 1, client->player->pos.x))
            return false;
        if (!send_message(client->pending_commands,
            client->command, client->socket, "Forward\n")) {
            fprintf(stderr, "%s[ERROR]%s Malloc error send_message\n", R, W);
            return false;
        }
        return true;
    }
    return true;
}

static bool go_to_broadcast_dir2(client_t *client, int x, int y, size_t d)
{
    if (d == 4 || d == 5 || d == 6) {
        if (!go_to_good_direction_y(client, y + 1, client->player->pos.y))
            return false;
        if (!send_message(client->pending_commands,
            client->command, client->socket, "Forward\n")) {
            fprintf(stderr, "%s[ERROR]%s Malloc error send_message\n", R, W);
            return false;
        }
        return true;
    }
    return (go_to_broadcast_dir3(client, x, d));
}

bool go_to_broadcast_direction(client_t *client)
{
    int x = client->player->pos.x;
    int y = client->player->pos.y;
    size_t d = client->player->broadcast_direction;

    printf("braodcast capte\n");
    if (d == 1 || d == 2 || d == 8) {
        if (!go_to_good_direction_y(client, y - 1, client->player->pos.y))
            return false;
        if (!send_message(client->pending_commands,
            client->command, client->socket, "Forward\n")) {
            fprintf(stderr, "%s[ERROR]%s Malloc error send_message\n", R, W);
            return false;
        }
        return true;
    }
    return (go_to_broadcast_dir2(client, x, y, d));
}

bool basic_command(client_t *client)
{
    if (client->pending_commands->lenght < 10 && !send_message(client->
        pending_commands,client->command, client->socket, "Look\n")) {
        fprintf(stderr, "%s[ERROR]%s Malloc error send_message\n", R, W);
        return false;
    }
    if (client->pending_commands->lenght < 10 && !send_message(client->
        pending_commands, client->command, client->socket, "Inventory\n")) {
        fprintf(stderr, "%s[ERROR]%s Malloc error send_message\n", R, W);
        return false;
    }
    return true;
}
