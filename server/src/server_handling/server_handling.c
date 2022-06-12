/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "core.h"

static int setup_new_client(server_t *serv, int fd)
{
    client_t *client = NULL;

    if (fd < 0) {
        printf("[ERROR] Creation of new connection failed\n");
        return ERROR;
    }
    client = client_create(fd);
    if (client == NULL) {
        printf("[ERROR] Creation of new client failed\n");
        close(fd);
        return ERROR;
    }
    if (list_push_data(serv->clients, (void *)client) == LIST_FAILURE) {
        printf("[ERROR] Insertion of new client failed\n");
        close(fd);
        client_destroy(client);
        return ERROR;
    }
    return SUCCESS;
}

static void server_accept_connection(server_t *serv)
{
    socklen_t socket_size = sizeof(sockaddr_in_t);
    int fd_temp = accept(serv->socket->fd,
        (struct sockaddr *)serv->socket->addr, &socket_size);

    if (setup_new_client(serv, fd_temp) == SUCCESS)
        printf("[INFO] New client connected.\n");
}

int server_loop(core_t *core)
{
    fd_set readfds = {0};
    fd_set writefds = {0};

    while (1) {
        set_read_fds(core->server, &readfds);
        set_write_fds(core->server, &writefds);
        nlib_select_fds(&readfds, &writefds);
        nlib_commands_update(core->server->commands_to_send, &writefds);
        clients_update(core, &readfds);
        if (FD_ISSET(core->server->socket->fd, &readfds) == 0)
            continue;
        server_accept_connection(core->server);
    }
}
