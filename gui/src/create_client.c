/*
** EPITECH PROJECT, 2022
** create_client.c
** File description:
** create_client gui
*/

#include "zappy_gui.h"

static void free_map(client_t *client)
{
    size_t max_y = client->size_map.y;
    size_t max_x = client->size_map.x;

    for (size_t y = 0; y < max_y; y++) {
        for (size_t x = 0; x < max_x; x++) {
            free(client->map[y][x].inv);
            free(client->map[y][x].player->inv);
            free(client->map[y][x].player);
        }
        free(client->map[y]);
    }
    free(client->map);

}

char *create_uuid()
{
    uuid_t binuuid;
    char *uuid = malloc(UUID_STR_LEN);

    if (!uuid)
        return NULL;
    uuid_generate_random(binuuid);
    uuid_unparse(binuuid, uuid);
    return uuid;
}

void free_client(client_t *client)
{
    close(client->socket->fd);
    shutdown(client->socket->fd, SHUT_RDWR);
    free(client->socket->addr);
    free(client->socket);
    if (client->map)
        free_map(client);
    list_destroy(client->command, (void (*)(void *))nlib_command_destroy);
    list_destroy(client->pending_commands, free);
    list_destroy(client->player, (void (*)(void *))free_player);
    list_destroy(client->team, free);
    free(client->uuid);
    free(client);
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
    if (!(client->command = list_create()) ||
        !(client->pending_commands = list_create()))
        return NULL;
    client->socket->addr->sin_family = AF_INET;
    client->socket->addr->sin_port = htons(arg->port);
    client->socket->addr->sin_addr.s_addr = inet_addr(arg->machine);
    client->size_map.x = -1;
    client->size_map.y = -1;
    client->map = NULL;
    if (!(client->player = list_create()) || !(client->team = list_create()))
        return NULL;
    return client;
}
