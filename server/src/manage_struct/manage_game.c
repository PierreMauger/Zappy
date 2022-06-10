/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "game.h"

static int is_team_same(char **teams, size_t to_comp)
{
    for (size_t j = 0; teams != NULL && teams[j] != NULL; j++) {
        if (strcmp(teams[to_comp], teams[j]) == 0) {
            return ERROR;
        }
    }
    return SUCCESS;
}

static int game_compare_teams(char **teams)
{
    size_t i = 0;

    for (; teams != NULL && teams[i] != NULL; i++) {
        if (is_team_same(teams, i) == ERROR) {
            return ERROR;
        }
    }
    if (i < 1)
        return ERROR;
    return SUCCESS;
}

game_t *game_create(char **teams, size_t width, size_t height,
    size_t cli_per_team)
{
    game_t *game = calloc(1, sizeof(game_t));
    team_t *team = NULL;

    if (game == NULL)
        return NULL;
    game->cli_per_team = cli_per_team;
    game->teams = list_create();
    game->trantorians = list_create();
    game->map = map_create(width, height);
    if (!game->teams || !game->trantorians || !game->map ||
        game_compare_teams(teams) == ERROR) {
        game_destroy(game);
        return NULL;
    }
    for (size_t i = 0; teams && teams[i]; i++) {
        team = team_create(teams[i]);
        if (team == NULL)
            return NULL;
        list_push_data(game->teams, team);
    }
    return game;
}

void game_destroy(game_t *game)
{
    if (game == NULL)
        return;
    if (game->teams)
        list_destroy(game->teams, (void (*)(void *))team_destroy);
    if (game->trantorians)
        list_destroy(game->trantorians, (void (*)(void *))trantorian_destroy);
    if (game->map)
        map_destroy(game->map);
    free(game);
}
