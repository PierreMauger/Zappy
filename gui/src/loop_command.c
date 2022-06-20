/*
** EPITECH PROJECT, 2022
** loop_command.c
** File description:
** loop_command gui
*/

#include "zappy_gui.h"

bool loop_command(client_t *client)
{
    node_t *node = NULL;
    char *pl = NULL;

    if (!send_message(
        client->pending_commands, client->command, client->socket, "mct\n")) {
        fprintf(stderr, "%s[ERROR]%s Malloc error send_message", R, W);
        return false;
    }
    foreach (client->player->head, node) {
        pl = malloc(sizeof(char) * (UUID_STR_LEN + 6));
        strcat(strcat(pl, "ppo #"), ((player_t *)node->data)->uuid);
        strcat(pl, "\n");
        if (!send_message(
            client->pending_commands, client->command, client->socket, pl)) {
            fprintf(stderr, "%s[ERROR]%s Malloc error send_message", R, W);
            return false;
        }
    }
    return true;
}
