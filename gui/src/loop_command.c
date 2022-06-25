/*
** EPITECH PROJECT, 2022
** loop_command.c
** File description:
** loop_command gui
*/

#include "zappy_gui.h"

static bool send_message_comm(client_t *client, char *com)
{
    if (!send_message(
        client->pending_commands, client->command, client->socket, com)) {
        fprintf(stderr, "%s[ERROR]%s Malloc error send_message", R, W);
        return false;
    }
    return true;
}

static bool players_command(client_t *client)
{
    node_t *node = NULL;
    char *pl = NULL;
    char *pin = NULL;
    char *plv = NULL;
    char *uuid = NULL;

    foreach (client->player->head, node) {
        uuid = ((player_t *)node->data)->uuid;
        pl = calloc(1, sizeof(char) * (strlen(uuid) + 10));
        pin = calloc(1, sizeof(char) * (strlen(uuid) + 10));
        plv = calloc(1, sizeof(char) * (strlen(uuid) + 10));
        strcat(strcat(strcat(pl, "ppo #"), uuid), "\n");
        strcat(strcat(strcat(pin, "pin #"), uuid), "\n");
        strcat(strcat(strcat(plv, "plv #"), uuid), "\n");
        if (!send_message_comm(client, pl) || !send_message_comm(client, pin)
            || !send_message_comm(client, plv))
            return false;
        free(pl);
        free(pin);
        free(plv);
    }
    return true;
}

bool loop_command(client_t *client)
{
    if (!send_message(
        client->pending_commands, client->command, client->socket, "mct\n")) {
        fprintf(stderr, "%s[ERROR]%s Malloc error send_message", R, W);
        return false;
    }
    if (!players_command(client))
        return false;
    return true;
}
