/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "core.h"

int parse_teams(int argc, char **argv, args_t *args)
{
    args->teams = calloc(argc - optind + 1, sizeof(char *));
    if (args->teams == NULL)
        return ERROR;
    for (size_t i = optind; i < argc; i++)
        args->teams[i - optind] = argv[i];
}

static int parse_param(args_t *args, int option)
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
        case 'c':
            args->cli_per_team = atol(optarg);
        break;
        case 'f':
            args->freq = atol(optarg);
        break;
        default:
            return ERROR;
    }
    return SUCCESS;
}

int parse_params(int argc, char **argv, args_t *args)
{
    int option = 0;
    bool has_team = false;

    while ((option = getopt(argc, argv, "p:x:y:c:f:n")) != -1) {
        if (option == 'n') {
            has_team = true;
            continue;
        }
        if (parse_param(args, option) == ERROR) {
            fprintf(stderr, "[ERROR] Unknown param\n");
            return ERROR;
        }
    };
    if (has_team == false) {
        fprintf(stderr, "[ERROR] No team specified\n");
        return ERROR;
    }
    get_teams(argc, argv, args);
    return SUCCESS;
}

args_t *init_args(void)
{
    args_t *args = calloc(1, sizeof(args_t));

    if (args == NULL)
        return NULL;
    args->port = DEFAULT_PORT;
    args->width = DEFAULT_WIDTH;
    args->height = DEFAULT_HEIGHT;
    args->cli_per_team = 1;
    args->freq = DEFAULT_FREQ;
    return args;
}

void free_args(args_t *args)
{
    if (args == NULL)
        return;
    free(args->teams);
    free(args);
}
