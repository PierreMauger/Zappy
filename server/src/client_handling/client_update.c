/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "core.h"

void client_push_exec_command(client_t *client, char *buffer)
{
    char *command = strtok(buffer, "\n");

    if (command == NULL) {
        printf("[ERROR] Command is not valid\n");
        return;
    }
    for (; command != NULL; command = strtok(NULL, "\n")) {
        if (list_push_data(client->command_list, (void *)strdup(command)) ==
            LIST_FAILURE) {
            printf("[ERROR] Insertion of command failed\n");
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
    printf("[INFO] received command: %s\n", buffer);
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
            list_remove_node(core->server->clients, node);
            list_destroy_node(node, (void (*)(void *))client_destroy);
            printf("[INFO] Client disconnected\n");
        }
        if (client->command_list->lenght > 0) {
            client_exec_command(core, client);
        }
    }
}
