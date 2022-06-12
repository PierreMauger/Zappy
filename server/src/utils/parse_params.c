/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "core.h"

static int parse_teams(char **argv, args_t *args)
{
    size_t team_nbr = 1;

    for (optind--; argv != NULL && argv[optind] != NULL &&
            argv[optind][0] != '-'; optind++) {
        args->teams = realloc(args->teams, sizeof(char *) * (team_nbr + 1));
        if (args->teams == NULL)
            return ERROR;
        args->teams[team_nbr - 1] = argv[optind];
        team_nbr++;
    }
    args->teams[team_nbr - 1] = NULL;
    return SUCCESS;
}

static int parse_param_2(args_t *args, int option, char **argv)
{
    switch (option) {
        break;
        case 'c':
            args->cli_per_team = atol(optarg);
        break;
        case 'f':
            args->freq = atol(optarg);
        break;
        case 'n':
            return parse_teams(argv, args);
        break;
        default:
            return ERROR;
    }
    return SUCCESS;
}

static int parse_param_1(args_t *args, int option, char **argv)
{
    switch (option) {
        case 'p':
            args->port = atoi(optarg);
        break;
        case 'x':
            args->width = atol(optarg);
        break;
        case 'y':
            args->height = atol(optarg);
        break;
        default:
            return parse_param_2(args, option, argv);
    }
    return SUCCESS;
}

int parse_params(int argc, char **argv, args_t *args)
{
    int option = 0;

    while ((option = getopt(argc, argv, "p:x:y:c:f:n:")) != -1) {
        if (parse_param_1(args, option, argv) == ERROR) {
            return ERROR;
        }
    };
    return SUCCESS;
}

int verif_params(args_t *args)
{
    if (args->port <= 0) {
        fprintf(stderr, "[ERROR] Invalid port\n");
        return ERROR;
    }
    if (args->width <= 0 || args->height <= 0) {
        fprintf(stderr, "[ERROR] Invalid size\n");
        return ERROR;
    }
    if (args->cli_per_team <= 0) {
        fprintf(stderr, "[ERROR] Invalid number of clients per team\n");
        return ERROR;
    }
    if (args->freq <= 0) {
        fprintf(stderr, "[ERROR] Invalid frequency\n");
        return ERROR;
    }
    if (args->teams == NULL) {
        fprintf(stderr, "[ERROR] No team name\n");
        return ERROR;
    }
    return SUCCESS;
}
