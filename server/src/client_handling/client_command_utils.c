/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "core.h"

void client_push_command(server_t *serv, client_t *client,
    char *buff, bool broadcast)
{
    command_t *command = NULL;

    if (buff == NULL || serv == NULL || client == NULL) {
        fprintf(stderr, "[ERROR] Cannot create command\n");
        return;
    }
    command = nlib_command_create(buff);
    if (command == NULL) {
        fprintf(stderr, "[ERROR] Cannot create command\n");
        return;
    }
    if (broadcast == true) {
        command_add_client(command, client);
    } else {
        command_add_all_clients(command, serv->clients);
    }
    list_push_data(serv->commands_to_send, command);
}
