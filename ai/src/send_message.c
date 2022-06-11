/*
** EPITECH PROJECT, 2022
** send_message.c
** File description:
** send_message ai
*/

#include "zappy_ai.h"

int send_message(client_t *client)
{
    command_t *command = nlib_command_create(strdup(client->player->team_name));
    
    if (!command)
        return false;
    if (list_push_data(command->socks, client->socket) == -1)
        return false;
    if (list_push_data(client->command, command) == -1)
        return false;
    printf("message = %s to fd = %d\n", ((command_t *)client->command->head->data)->to_write,
        ((socket_t *)((command_t *)client->command->head->data)->socks->head->data)->fd);
    return true;
}