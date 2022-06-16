/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "core.h"

bool game_clock_update(size_t freq)
{
    static clock_t elapsed = 0;

    elapsed += clock();
    if ((elapsed / CLOCKS_PER_SEC) >= (long int)(1 / freq)) {
        for (; (elapsed / CLOCKS_PER_SEC) >= (long int)(1 / freq);
            elapsed -= (1 / freq));
        return true;
    }
    return false;
}

void game_update(core_t *core)
{
    // if (game_clock_update(core->game->freq)) {
    //     game_update_map(core->game->map);
    //     game_update_trantorians(core->game->trantorians);
    // }
}
