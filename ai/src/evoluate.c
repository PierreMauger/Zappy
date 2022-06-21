/*
** EPITECH PROJECT, 2022
** look_around.c
** File description:
** look_around ai
*/

#include "zappy_ai.h"

bool level_1(client_t *client)
{
    if (client->player->inv->linemate < 1) {
        if (!path_finding_object(client, "linemate"))
            return false;
        if (!get_nb_object(client, client->player->inv->linemate, 1,
            "linemate"))
            return false;
    }
    return true;
}

bool level_2(client_t *client)
{
    if (client->player->inv->linemate < 1) {
        if (!path_finding_object(client, "linemate"))
            return false;
        if (!get_nb_object(client, client->player->inv->linemate, 1,
            "linemate"))
            return false;
    }
    if (client->player->inv->deraumere < 1) {
        if (!path_finding_object(client, "deraumere"))
            return false;
        if (!get_nb_object(client, client->player->inv->deraumere, 1,
            "deraumere"))
            return false;
    }
    if (client->player->inv->sibur < 1) {
        if (!path_finding_object(client, "sibur"))
            return false;
        if (!get_nb_object(client, client->player->inv->sibur, 1, "sibur"))
            return false;
    }
    return true;
}

bool level_3(client_t *client)
{
    if (client->player->inv->linemate < 2) {
        if (!path_finding_object(client, "linemate"))
            return false;
        if (!get_nb_object(client, client->player->inv->linemate, 2,
            "linemate"))
            return false;
    }
    if (client->player->inv->sibur < 1) {
        if (!path_finding_object(client, "sibur"))
            return false;
        if (!get_nb_object(client, client->player->inv->sibur, 1, "sibur"))
            return false;
    }
    if (client->player->inv->phiras < 1) {
        if (!path_finding_object(client, "phiras"))
            return false;
        if (!get_nb_object(client, client->player->inv->phiras, 1, "phiras"))
            return false;
    }
    return true;
}

static bool split_level_4(client_t *client)
{
    if (client->player->inv->phiras < 1) {
        if (!path_finding_object(client, "phiras"))
            return false;
        get_nb_object(client, client->player->inv->phiras, 1, "phiras");
    }
    if (client->player->inv->deraumere < 1) {
        if (!path_finding_object(client, "deraumere"))
            return false;
        get_nb_object(client, client->player->inv->deraumere, 1, "deraumere");
    }
    return true;
}

bool level_4(client_t *client)
{
    if (client->player->inv->linemate < 1) {
        if (!path_finding_object(client, "linemate"))
            return false;
        get_nb_object(client, client->player->inv->linemate, 1, "linemate");
    }
    if (client->player->inv->sibur < 2) {
        if (!path_finding_object(client, "sibur"))
            return false;
        get_nb_object(client, client->player->inv->sibur, 2, "sibur");
    }
    return split_level_4(client);
}