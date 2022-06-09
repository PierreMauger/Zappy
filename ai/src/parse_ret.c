/*
** EPITECH PROJECT, 2022
** init_client.c
** File description:
** init_client ai
*/

#include "zappy_ai.h"

static bool init_header(client_t *client, char *str)
{
    client->init = true;
    if (strcmp(str, "WELCOME\n") == 0) {
        //send_message(client->team_name);
        return true;
    }
    if (atoi(str) < 1 && !client->client_connected) {
        fprintf(stderr, "%s[ERROR]%s too many clients in this team", R, W);
        return false;
    }
    if (atoi(str) >= 1 && !client->client_connected) {
        client->client_connected = true;
        return true;
    }
    client->size_map.x = atoi(str);
    client->size_map.y = atoi(strchr(str, ' '));
    client->init = false;
    return true;
}

bool parse_return(client_t *client, char *str)
{
    if (strcmp(str, "WELCOME\n") == 0 || client->init)
        return (init_header(client, str));
    if (client->size_map.x == -1 && client->size_map.y == -1)
        return true;
    check_command();
    return true;
}
