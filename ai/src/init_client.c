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

void sig_handler_c(__attribute__((unused)) int signum)
{
    bool *is_end = get_value();
    (*is_end) = true;
}

bool check_fd_isset(client_t *client)
{
    char *temp = NULL;

    if (FD_ISSET(client->sockfd, &client->readfds)) {
        temp = nlib_read_socket(client->sockfd);
        if (temp == NULL) {
            fprintf(stderr, "%s[ERROR]%s malloc buffer\n", R, W);
            return true;
        }
        if (!parse_return(client, temp))
            return true;
        free(temp);
    }
    return false;
}

bool loop_client(client_t *client)
{
    int sel = 0;

    while (1) {
        FD_ZERO(&client->readfds);
        FD_ZERO(&client->writefds);
        FD_SET(client->sockfd, &client->readfds);
        FD_SET(client->sockfd, &client->writefds);
        sel = nlib_select_fds(&client->readfds, &client->writefds);
        if (sel == -1 || *(get_value()))
            break;
        if (check_fd_isset(client))
            break;
    }
    return true;
}

bool init_client(arg_t *arg)
{
    client_t *client = create_client(arg);
    bool ret = false;

    if (connect(client->sockfd,
        (struct sockaddr *)&client->servaddr, sizeof(client->servaddr)) < 0) {
        printf("%s[ERROR]%s Connect Failed \n", R, W);
        close(client->sockfd);
        free(client);
        free(arg);
        exit(ERROR_EXIT);
    }
    ret = loop_client(client);
    close(client->sockfd);
    shutdown(client->sockfd, SHUT_RDWR);
    free(client);
    return ret;
}
