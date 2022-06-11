/*
** EPITECH PROJECT, 2022
** send_message.c
** File description:
** send_message ai
*/

#include "nlib.h"

bool nlib_send_message(list_t *list, socket_t *socket, char *message)
{
    command_t *command = nlib_command_create(strdup(message));
    
    if (!command)
        return false;
    if (list_push_data(command->socks, socket) == -1)
        return false;
    if (list_push_data(list, command) == -1)
        return false;
    printf("message = [%s] to fd = [%d]\n", ((command_t *)list->head->data)->to_write,
        ((socket_t *)((command_t *)list->head->data)->socks->head->data)->fd);
    return true;
}