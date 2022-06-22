/*
** EPITECH PROJECT, 2022
** look_around.c
** File description:
** look_around ai
*/

#include "zappy_ai.h"

bool level_3(client_t *client)
{
    if (client->player->inv->linemate < 2) {
        if (!path_finding_object(client, "linemate"))
            return false;
        if (!get_object(client, client->player->inv->linemate, 2, "linemate"))
            return false;
    }
    if (client->player->inv->sibur < 1) {
        if (!path_finding_object(client, "sibur"))
            return false;
        if (!get_object(client, client->player->inv->sibur, 1, "sibur"))
            return false;
    }
    if (client->player->inv->phiras < 1) {
        if (!path_finding_object(client, "phiras"))
            return false;
        if (!get_object(client, client->player->inv->phiras, 1, "phiras"))
            return false;
    }
    return ask_player(client, 2, (client->player->level + '0'));
}

static bool split_level_4(client_t *client)
{
    if (client->player->inv->phiras < 1) {
        if (!path_finding_object(client, "phiras"))
            return false;
        if (!get_object(client, client->player->inv->phiras, 1, "phiras"))
            return false;
    }
    if (client->player->inv->deraumere < 1) {
        if (!path_finding_object(client, "deraumere"))
            return false;
        if (!get_object(client, client->player->inv->deraumere, 1, "deraumere"))
            return false;
    }
    return ask_player(client, 4, (client->player->level + '0'));
}

bool level_4(client_t *client)
{
    if (client->player->inv->linemate < 1) {
        if (!path_finding_object(client, "linemate"))
            return false;
        if (!get_object(client, client->player->inv->linemate, 1, "linemate"))
            return false;
    }
    if (client->player->inv->sibur < 2) {
        if (!path_finding_object(client, "sibur"))
            return false;
        if (!get_object(client, client->player->inv->sibur, 2, "sibur"))
            return false;
    }
    return split_level_4(client);
}

static bool split_level_5(client_t *client)
{
    if (client->player->inv->mendiane < 3) {
        if (!path_finding_object(client, "mendiane"))
            return false;
        if (!get_object(client, client->player->inv->mendiane, 3, "mendiane"))
            return false;
    }
    return ask_player(client, 4, (client->player->level + '0'));
}

bool level_5(client_t *client)
{
    if (client->player->inv->linemate < 1) {
        if (!path_finding_object(client, "linemate"))
            return false;
        if (!get_object(client, client->player->inv->linemate, 1, "linemate"))
            return false;
    }
    if (client->player->inv->deraumere < 2) {
        if (!path_finding_object(client, "deraumere"))
            return false;
        if (!get_object(client, client->player->inv->deraumere, 2, "deraumere"))
            return false;
    }
    if (client->player->inv->sibur < 1) {
        if (!path_finding_object(client, "sibur"))
            return false;
        if (!get_object(client, client->player->inv->sibur, 1, "sibur"))
            return false;
    }
    return split_level_5(client);
}
