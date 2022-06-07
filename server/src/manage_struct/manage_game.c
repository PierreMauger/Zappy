/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "game.h"

game_t *game_create(char **teams, size_t width, size_t height)
{
    game_t *game = calloc(1, sizeof(game_t));
    team_t *team = NULL;

    if (game == NULL)
        return NULL;
    game->teams = list_create();
    game->trantorians = list_create();
    game->map = map_create(width, height);
    if (!game->teams || !game->trantorians || !game->map)
        return (NULL);
    for (size_t i = 0; teams && teams[i]; i++) {
        team = team_create(teams[i]);
        if (!team)
            return (NULL);
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
