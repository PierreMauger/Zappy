/*
** EPITECH PROJECT, 2022
** create_client.c
** File description:
** create_client ai
*/

#include "zappy_ai.h"

void free_client(client_t *client)
{
    close(client->socket->fd);
    shutdown(client->socket->fd, SHUT_RDWR);
    free(client->socket->addr);
    free(client->socket);
    list_destroy(client->command, (void (*)(void *))nlib_command_destroy);
    free(client->player);
    free(client);
}

static player_t *crt_play(arg_t *arg)
{
    player_t *player = malloc(sizeof(player_t));

    if (!player)
        return NULL;
    player->team_name = arg->name;
    player->pos.x = -1;
    player->pos.y = -1;
    return player;
}

client_t *create_client(arg_t *arg)
{
    client_t *client = malloc(sizeof(client_t));

    if (!client || !(client->socket = malloc(sizeof(socket_t))))
        return NULL;
    client->socket->addr = calloc(1, sizeof(sockaddr_in_t));
    if ((client->socket->fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "%s[ERROR]%s socket creation failed\n", R, W);
        exit(ERROR_EXIT);
    }
    if (!(client->command = list_create()) || !(client->player = crt_play(arg)))
        return NULL;
    client->socket->addr->sin_family = AF_INET;
    client->socket->addr->sin_port = htons(arg->port);
    client->socket->addr->sin_addr.s_addr = inet_addr(arg->machine);
    client->init = false;
    client->client_connected = false;
    client->size_map.x = -1;
    client->size_map.y = -1;
    return client;
}
