/*
** EPITECH PROJECT, 2022
** init_client.c
** File description:
** init_client ai
*/

#include "zappy_ai.h"

static bool get_size_map(client_t *client, char *str)
{
    client->size_map.x = atoi(str);
    client->size_map.y = atoi(strchr(str, ' '));
    if (client->size_map.x <= 0 || client->size_map.y <= 0) {
        fprintf(stderr, "%s[ERROR]%s bad size map", R, W);
        return false;
    }
    if (!create_map(client)) {
        fprintf(stderr, "%s[ERROR]%s can't malloc map\n", R, W);
        return false;
    }
    if (client->client_connected)
        client->init = false;
    return true;
}

static bool get_number_client(client_t *client, char *str)
{
    if (atoi(str) < 1 && !client->client_connected) {
        fprintf(stderr, "%s[ERROR]%s too many clients in this team\n", R, W);
        return false;
    }
    if (atoi(str) >= 1 && !client->client_connected)
        client->client_connected = true;
    if (client->size_map.x != -1)
        client->init = false;
    return true;
}

static bool init_header(client_t *client, char *str)
{
    char *team_new_line = NULL;

    client->init = true;
    if (strcmp(str, "WELCOME") == 0) {
        if (!(team_new_line = add_newline(client->player->team_name)))
            return false;
        if (!send_message(NULL, client->command, client->socket, team_new_line))
            return false;
        free(team_new_line);
        return true;
    }
    for (; str[0] == ' '; (char *)((size_t)(str++)));
    if (!(strchr(str, ' ')))
        return get_number_client(client, str);
    else
        get_size_map(client, str);
    return true;
}

static char *get_arg(char *command, char *str)
{
    char *arg = NULL;
    size_t i = 0;
    size_t len = 0;
    size_t n = 0;

    for (i = 0; command[i] != '\0' && command[i] != ' '; i++);
    if (command[i] == '\0')
        return NULL;
    command[i] = '\0';
    if (strcmp(str, "ko") == 0)
        return strdup(str);
    i++;
    n = i;
    for (; command[i] != '\0'; i++, len++);
    arg = malloc(sizeof(char) * (len + 1));
    for (i = n, len = 0; command[i] != '\0'; i++, len++)
        arg[len] = command[i];
    arg[len] = '\0';
    return arg;
}

bool parse_return(client_t *client, char *str)
{
    char *command = NULL;
    char *arg = NULL;

    printf("command received : [%s]\n", str);
    if (strcmp(str, "WELCOME") == 0 || client->init)
        return (init_header(client, str));
    if (!(command = list_pop_head(client->pending_commands)))
        return true;
    arg = get_arg(command, str);
    printf("command = <%s> arg = <%s>\n", command, arg);
    for (int i = 0; com[i].cmd != NULL; i++) {
        if (strcmp(com[i].cmd, command) == 0) {
            com[i].func_ptr(client, ((arg) ? arg : str));
            break;
        }
    }
    free(command);
    free(arg);
    return true;
}
