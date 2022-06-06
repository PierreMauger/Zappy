/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** include
*/

#ifndef SERVER_H
    #define SERVER_H

    #define _GNU_SOURCE

    #define SUCCESS (0)
    #define ERROR (1)
    #define EXIT (2)

    #define ERROR_EXIT (84)

    #define UNUSED __attribute__((unused))

    #include <sys/types.h>
    #include <linux/limits.h>
    #include <sys/stat.h>

    #include <errno.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <stdbool.h>
    #include <regex.h>
    #include <fcntl.h>

    #include "list.h"
    #include "nlib.h"

#endif // SERVER_H
