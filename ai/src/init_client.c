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

bool split_loop_client(client_t *client)
{
    char *temp = NULL;

    if (FD_ISSET(client->sockfd, &client->readfds)) {
        temp = read_socket(client->sockfd);
        if (temp == NULL) {
            printf("Error malloc buffer\n");
            return true;
        }
        //parse_return(temp);
    }
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
        if (split_loop_client(client))
            break;
    }
    return true;
}

int init_client(arg_t *arg)
{
    client_t *client = create_client(arg);

    if (connect(client->sockfd,
        (struct sockaddr *)&client->servaddr, sizeof(client->servaddr)) < 0) {
        printf("Error : Connect Failed \n");
        close(client->sockfd);
        free(client);
        free(arg);
        exit(ERROR_EXIT);
    }
    loop_client(client);
    close(client->sockfd);
    shutdown(client->sockfd, SHUT_RDWR);
    free(client);
    return 0;
}
