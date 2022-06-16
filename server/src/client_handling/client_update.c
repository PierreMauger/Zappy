/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "core.h"

void client_exec_command(core_t *core, client_t *client)
{
    char *command = list_pop_last(client->command_list);

    if (command == NULL) {
        fprintf(stderr, "[ERROR] Cannot get command\n");
        return;
    }
    if (client->type == CLI_DEFAULT) {
        client_def_search_command(core, client, command);
    } else if (client->type == CLI_GUI) {
        client_gui_search_command(core, client, command);
    } else {
        client_define_type(core, client, command);
    }
    free(command);
}

void client_push_exec_command(client_t *client, char *buffer)
{
    char *command = strtok(buffer, "\n");

    if (command == NULL) {
        fprintf(stderr, "[ERROR] Command is not valid\n");
        return;
    }
    for (; command != NULL; command = strtok(NULL, "\n")) {
        if (client->command_list->lenght >= 10) {
            fprintf(stderr, "[ERROR] Command list is full\n");
            return;
        }
        if (list_push_data(client->command_list, (void *)strdup(command)) ==
            LIST_FAILURE) {
            fprintf(stderr, "[ERROR] Insertion of command failed\n");
            return;
        }
        printf("[INFO] Command %s pushed\n", command);
    }
}

int client_get_command(client_t *client)
{
    char *buffer = NULL;

    buffer = nlib_read_socket(client->sock->fd);
    if (buffer == NULL)
        return EXIT;
    printf("[INFO] received command: \"%s\"", buffer);
    client_push_exec_command(client, buffer);
    free(buffer);
    return SUCCESS;
}

void clients_update(core_t *core, fd_set *readfds)
{
    node_t *node = NULL;
    node_t *safe = NULL;
    client_t *client = NULL;

    foreach_safe(core->server->clients->head, node, safe) {
        client = (client_t *)node->data;
        if (FD_ISSET(client->sock->fd, readfds) &&
                client_get_command(client) == EXIT) {
            list_destroy_data_node(core->game->trantorians, client->trantorian,
                (void (*)(void *))trantorian_destroy);
            list_remove_node(core->server->clients, node);
            list_destroy_node(node, (void (*)(void *))client_destroy);
            printf("[INFO] Client disconnected\n");
        } else if (client->command_list->lenght > 0) {
            client_exec_command(core, client);
        }
    }
}
