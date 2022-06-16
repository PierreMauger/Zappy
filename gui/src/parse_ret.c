/*
** EPITECH PROJECT, 2022
** init_client.c
** File description:
** init_client gui
*/

#include "zappy_gui.h"

static bool init_header(client_t *client)
{
    return (send_message(NULL,
        client->command, client->socket, client->uuid));
}

static char *get_command_arg(char *str)
{
    char *arg = NULL;
    size_t i = 0;
    size_t n = 0;
    size_t j = 0;

    for (; str[i] == ' '; i++);
    for (; str[i] != '\0' && str[i] != ' '; i++);
    if (str[i] == '\0')
        return NULL;
    for (n = i; str[n] != '\0'; n++);
    arg = malloc(sizeof(char) * (n + 1));
    if (!arg) {
        fprintf(stderr, "%s[ERROR]%s can't malloc\n", R, W);
        return NULL;
    }
    for (; str[i] == ' '; i++);
    for (n = i; str[n] != '\0'; n++, j++)
        arg[j] = str[n];
    arg[j] = '\0';
    return arg;
}

static char *get_command_name(char *str)
{
    char *command_name = NULL;
    size_t i = 0;
    size_t n = 0;

    for (; str[i] != '\0' && str[i] != ' '; i++);
    command_name = malloc(sizeof(char) * (i + 1));
    if (!command_name) {
        fprintf(stderr, "%s[ERROR]%s can't malloc\n", R, W);
        return NULL;
    }
    for (n = 0; str[n] != '\0' && str[n] != ' '; n++)
        command_name[n] = str[n];
    command_name[n] = '\0';
    return command_name;
}

bool parse_return(client_t *client, char *str)
{
    char *command_name = NULL;
    char *arg = NULL;

    printf("response [%s]\n", str);
    if (strcmp(str, "WELCOME\n") == 0)
        return (init_header(client));
    if (!(command_name = get_command_name(str)))
        return false;
    arg = (strcmp(command_name, "suc") == 0 || strcmp(command_name, "sbp") == 0)
        ? strdup(str) : get_command_arg(str);
    for (int i = 0; com[i].cmd != NULL; i++) {
        if (strcmp(com[i].cmd, command_name) == 0) {
            com[i].func_ptr(client, arg);
            break;
        }
    }
    free(command_name);
    free(arg);
    return true;
}
