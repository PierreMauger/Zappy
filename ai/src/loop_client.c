/*
** EPITECH PROJECT, 2022
** init_client.c
** File description:
** init_client ai
*/

#include "zappy_ai.h"

bool *get_value(void)
{
    static bool value = false;

    return (&value);
}

void sig_handler(__attribute__((unused)) int signum)
{
    bool *is_end = get_value();
    (*is_end) = true;
}

static bool check_fd_isset(client_t *client)
{
    char *temp = NULL;

    if (FD_ISSET(STDIN_FILENO, &client->readfds)) {
        read_stdin(client);
        return false;
    }
    if (FD_ISSET(client->socket->fd, &client->readfds)) {
        temp = nlib_read_socket(client->socket->fd);
        if (temp == NULL) {
            fprintf(stderr, "%s[ERROR]%s can't read socket\n", R, W);
            return true;
        }
        if (!parse_return(client, temp)) {
            free(temp);
            return true;
        }
        free(temp);
    }
    return false;
}

static bool loop_client(client_t *client)
{
    int sel = 0;

    while (1) {
        FD_ZERO(&client->readfds);
        FD_ZERO(&client->writefds);
        FD_SET(STDIN_FILENO, &client->readfds);
        FD_SET(client->socket->fd, &client->readfds);
        FD_SET(client->socket->fd, &client->writefds);
        sel = nlib_select_fds(&client->readfds, &client->writefds);
        if (sel == -1 || *(get_value()))
            break;
        if (check_fd_isset(client))
            break;
        nlib_commands_update(client->command, &client->writefds);
    }
    return true;
}

bool init_client(arg_t *arg)
{
    client_t *client = create_client(arg);
    bool ret = false;

    if (!client) {
        printf("%s[ERROR]%s Can't malloc client\n", R, W);
        return false;
    }
    if (connect(client->socket->fd, (struct sockaddr *)
            client->socket->addr, sizeof(*(client->socket->addr))) < 0) {
        printf("%s[ERROR]%s Connect Failed\n", R, W);
        free_client(client);
        return false;
    }
    ret = loop_client(client);
    free_client(client);
    return ret;
}
