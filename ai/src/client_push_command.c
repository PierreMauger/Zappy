/*
** EPITECH PROJECT, 2022
** create_client.c
** File description:
** create_client ai
*/

#include "zappy_ai.h"

void client_push_exec_command(client_t *client, char *buffer)
{
    char *command = strtok(buffer, "\n");

    if (command == NULL) {
        fprintf(stderr, "[ERROR] Command is not valid\n");
        return;
    }
    for (; command != NULL; command = strtok(NULL, "\n")) {
        if (client->received_commands->lenght >= 10) {
            fprintf(stderr, "[ERROR] Command list is full\n");
            return;
        }
        if (list_push_data(client->received_commands,
            (void *)strdup(command)) == LIST_FAILURE) {
            fprintf(stderr, "[ERROR] Insertion of command failed\n");
            return;
        }
        printf("%s[INFO]%s Command \"%s\" pushed in list\n", G, W, command);
    }
}

bool loop_parse_return(client_t *client)
{
    node_t *node = NULL;
    node_t *node_save = NULL;

    foreach_safe (client->received_commands->head, node, node_save) {
        if (!parse_return(client, (char *)node->data))
            return true;
        list_destroy_data_node(client->received_commands, node->data, free);
    }
    return false;
}
