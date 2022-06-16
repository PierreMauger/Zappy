/*
** EPITECH PROJECT, 2022
** read_socket.c
** File description:
** read_socket
*/

#include "nlib.h"

char *nlib_read_socket(int fd)
{
    char *buffer = calloc(READ_SIZE * 10, sizeof(char));
    ssize_t size_read = 0;

    if (buffer == NULL)
        return NULL;
    size_read = read(fd, buffer, READ_SIZE);
    if (size_read <= 0) {
        free(buffer);
        return NULL;
    }
    return buffer;
}
