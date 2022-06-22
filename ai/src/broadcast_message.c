/*
** EPITECH PROJECT, 2022
** broadcast.c
** File description:
** broadcast ai
*/

#include "zappy_ai.h"

void interpret_message(client_t *client, char *message, size_t direction)
{
    size_t level = atoi(message);

    if (level == 0)
        return;
    if (level == client->player->level)
        client->player->broadcast_direction = direction;
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