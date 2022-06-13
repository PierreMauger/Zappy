/*
** EPITECH PROJECT, 2022
** stdin.c
** File description:
** stdin ai
*/

#include "zappy_ai.h"

char *get_inputs(void)
{
    char buffer[4096];
    int ret = read(0, buffer, 4096);

    if (ret <= 0) {
        fprintf(stderr, "%s[ERROR]%s can't read input\n", R, W);
        return NULL;
    }
    if (ret <= 1) {
        fprintf(stderr, "%s[WARNING]%s empty input\n", M, W);
        return NULL;
    }
    buffer[ret] = '\0';
    return (strdup(buffer));
}

int read_stdin(client_t *client)
{
    char *input = get_inputs();

    if (!input)
        return 1;
    send_message(client->command, client->socket, strdup(input));
    free(input);
    return 1;
}
