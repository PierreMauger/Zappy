/*
** EPITECH PROJECT, 2022
** init_client.c
** File description:
** init_client ai
*/

#include "zappy_ai.h"

static bool get_number_client(client_t *client, char *str)
{
    if (atoi(str) < 1 && !client->client_connected) {
        fprintf(stderr, "%s[ERROR]%s too many clients in this team", R, W);
        return false;
    }
    if (atoi(str) >= 1 && !client->client_connected)
        client->client_connected = true;
    if (client->size_map.x != -1)
        client->init = false;
    return true;
}

static bool init_header(client_t *client, char *str)
{
    client->init = true;
    if (strcmp(str, "WELCOME\n") == 0)
        return (send_message(NULL,
            client->command, client->socket, client->player->team_name));
    if (!(strchr(str, ' ')))
        return get_number_client(client, str);
    else {
        client->size_map.x = atoi(str);
        client->size_map.y = atoi(strchr(str, ' '));
        if (client->size_map.x <= 0 || client->size_map.y <= 0) {
            fprintf(stderr, "%s[ERROR]%s bad size map", R, W);
            return false;
        }
        if (client->client_connected)
            client->init = false;
    }
    return true;
}

bool parse_return(client_t *client, char *str)
{
    char *command = NULL;

    printf("commande reçu : %s\n", str);
    if (strcmp(str, "WELCOME\n") == 0 || client->init)
        return (init_header(client, str));
    command = list_pop_head(client->pending_commands);
    if (!command)
        return true;
    for (int i = 0; com[i].cmd != NULL; i++) {
        if (strcmp(com[i].cmd, command) == 0) {
            com[i].func_ptr(str);
            break;
        }
    }
    free(command);
    return true;
}
