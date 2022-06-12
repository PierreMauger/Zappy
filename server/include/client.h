/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** include
*/

#ifndef CLIENT_H
    #define CLIENT_H

    #include <uuid/uuid.h>

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>

    #include "nlib.h"

typedef enum {
    CLI_DEFAULT,
    CLI_GUI,
} client_type_e;

typedef struct {
    socket_t *sock;
    list_t *exec_commands;
    uuid_t id_team;
    client_type_e type;
} client_t;

void client_destroy_command(char *command);
client_t *client_create(int fd);
void client_destroy(client_t *client);

#endif // CLIENT_H
