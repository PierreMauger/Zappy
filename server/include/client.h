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

typedef enum {
    CLI_DEFAULT,
    CLI_GUI,
} client_type_e;

typedef struct {
    int fd;
    uuid_t id_team;
    client_type_e type;
} client_t;

client_t *client_create(int fd, uuid_t id_team);
void client_destroy(client_t *client);

#endif // CLIENT_H
