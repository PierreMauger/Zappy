/*
** EPITECH PROJECT, 2022
** broadcast.c
** File description:
** broadcast ai
*/

#include "zappy_ai.h"

void interpret_message(client_t *client, char *message, size_t direction)
{
    char *team_name = get_one_word(message);
    size_t level = atoi(go_next_chr(message, ' '));

    if (level == 0)
        return;
    if (level == client->player->level &&
        strcmp(team_name, client->player->team_name) == 0)
        client->player->broadcast_direction = direction;
    free(team_name);
}

bool message_broadcast(client_t *client, char *str)
{
    char *message = NULL;
    size_t direction = atoi(go_next_chr(str, ' '));

    message = get_one_word(go_next_chr(str, ','));
    if (!message) {
        fprintf(stderr, "%s[ERROR]%s Malloc error get_one_word\n", R, W);
        return false;
    }
    interpret_message(client, message, direction);
    free(message);
    return true;
}
