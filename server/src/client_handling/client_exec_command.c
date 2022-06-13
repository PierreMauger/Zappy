/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "core.h"

static const method_t methods[] = {
    {"Forward", command_forward},
    {"Right", command_right},
    {"Left", command_left},
    {"Look", command_look},
    {"Inventory", command_inventory},
    {"Broadcast", command_broadcast},
    {"Connect_nbr", command_connect_nbr},
    {"Fork", command_fork},
    {"Eject", command_eject},
    {"Take", command_take},
    {"Set", command_set},
    {"Incantation", command_incantation},
};

void client_unknown_command(server_t *serv, client_t *client)
{
    char *buff = strdup("ko");
    command_t *command = NULL;

    if (buff == NULL) {
        printf("[ERROR] Cannot create command\n");
        return;
    }
    command = nlib_command_create(buff);
    command_add_client(command, client);
    list_push_data(serv->commands_to_send, command);
    printf("[ERROR] Unknown command\n");
}

void client_search_command(core_t *core, client_t *client, char *command)
{
    for (size_t i = 0; i < sizeof(methods) / sizeof(method_t); i++) {
        if (strcmp(command, methods[i].name) == 0) {
            methods[i].func(core, client);
            return;
        }
    }
    client_unknown_command(core->server, client);
}

void client_exec_command(core_t *core, client_t *client)
{
    char *command = list_pop_last(client->command_list);

    if (command == NULL) {
        printf("[ERROR] Cannot get command\n");
        return;
    }
    client_search_command(core, client, command);
}
