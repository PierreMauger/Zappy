/*
** EPITECH PROJECT, 2022
** nlib.h
** File description:
** nlib
*/

#ifndef NLIB_H
    #define NLIB_H

    #define READ_SIZE (4096)

    #include <sys/socket.h>
    #include <sys/select.h>
    #include <sys/time.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <linux/limits.h>

    #include <stdlib.h>
    #include <stdio.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include <errno.h>
    #include <string.h>
    #include <stdarg.h>

typedef struct sockaddr_in sockaddr_in_t;

typedef struct {
    int fd;
    sockaddr_in_t *addr;
} socket_t;

socket_t *nlib_create_socket(void);
socket_t *nlib_init_socket(socket_t *sock, int port, size_t nbr_connection);
void nlib_destroy_socket(socket_t *sock);

int nlib_select_fds(fd_set *readfds, fd_set *writefds);
int nlib_select_fds_time(fd_set *readfd, fd_set *writefds, double time);

char *nlib_read_socket(int fd);
int nlib_write_socket(const socket_t *sock, const char *format, ...);

#endif // NLIB_H
