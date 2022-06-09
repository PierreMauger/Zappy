/*
** EPITECH PROJECT, 2022
** create_client.c
** File description:
** create_client ai
*/

#include "zappy_ai.h"

client_t *create_client(arg_t *arg)
{
    client_t *client = malloc(sizeof(client_t));

    if (!client)
        return NULL;
    if ((client->sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "%s[ERROR]%s socket creation failed\n", R, W);
        exit(ERROR_EXIT);
    }
    memset(&client->servaddr, 0, sizeof(client->servaddr));
    client->servaddr.sin_family = AF_INET;
    client->servaddr.sin_port = htons(arg->port);
    client->servaddr.sin_addr.s_addr = inet_addr(arg->machine);
    client->team_name = arg->name;
    client->init = false;
    client->client_connected = false;
    client->size_map.x = -1;
    client->size_map.y = -1;
    return client;
}