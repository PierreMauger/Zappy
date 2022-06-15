/*
** EPITECH PROJECT, 2022
** broadcast.c
** File description:
** broadcast gui
*/

#include "zappy_gui.h"

static player_t *split_create_player(player_t *player, char *save)
{
    char *temp = NULL;

    save = move_str(save);
    temp = get_one_word(save);
    player->dir = atoi(temp);
    free(temp);
    save = move_str(save);
    temp = get_one_word(save);
    player->level = atoi(temp);
    free(temp);
    save = move_str(save);
    player->team_name = get_one_word(save);
    free(save);
    return player;
}

static player_t *create_player(char *str)
{
    char *save = strdup(str);
    char *temp = NULL;
    player_t *player = malloc(sizeof(player_t));

    if (!player)
        return NULL;
    player->uuid = get_one_word(save);
    save = move_str(save);
    temp = get_one_word(save);
    player->pos.x = atoi(temp);
    free(temp);
    save = move_str(save);
    temp = get_one_word(save);
    player->pos.y = atoi(temp);
    free(temp);
    return (split_create_player(player, save));
}

int pnw(client_t *client, char *str)
{
    player_t *player;

    if (strcmp(str, "suc\n") == 0) {
        fprintf(stderr, "%s[ERROR]%s suc command received", R, W);
        return 1;
    }
    if (strcmp(str, "sbp\n") == 0) {
        fprintf(stderr, "%s[ERROR]%s bad arguments", R, W);
        return 1;
    }
    player = create_player(str);
    if (!player) {
        fprintf(stderr, "%s[ERROR]%s can't malloc player", R, W);
        return 1;
    }
    list_push_data(client->player, player);
    return 0;
}