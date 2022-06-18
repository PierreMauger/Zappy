/*
** EPITECH PROJECT, 2022
** init_client.c
** File description:
** init_client ai
*/

#include "zappy_ai.h"

char *add_newline(char *str)
{
    char *new_str = malloc(sizeof(char) * (strlen(str) + 2));

    if (!new_str)
        return NULL;
    strcat(strcpy(new_str, str), "\n");
    return (new_str);
}

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

bool parse_return(client_t *client, char *str)
{
    char *command = NULL;

    printf("command received : [%s]\n", str);
    if (strcmp(str, "WELCOME") == 0 || client->init)
        return (init_header(client, str));
    command = list_pop_head(client->pending_commands);
    if (!command)
        return true;
    printf("command = <%s>\n", command);
    for (int i = 0; com[i].cmd != NULL; i++) {
        if (strcmp(com[i].cmd, command) == 0) {
            com[i].func_ptr(client, str);
            break;
        }
    }
    free(command);
    return true;
}
