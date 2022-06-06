/*
** EPITECH PROJECT, 2022
** read_socket.c
** File description:
** read_socket
*/

#include "nlib.h"

static char *filter_buffer(char *buffer)
{
    char *new_buffer = strchr(buffer, '\n');

    if (new_buffer == NULL)
        return NULL;
    *new_buffer = '\0';
    return buffer;
}

char *nlib_read_socket(int fd)
{
    char buffer[READ_SIZE] = {0};
    char *temp = NULL;
    ssize_t size_read = 0;

    size_read = read(fd, buffer, READ_SIZE);
    if (size_read <= 0)
        return NULL;
    temp = filter_buffer(buffer);
    return temp ? strdup(temp) : NULL;
}
