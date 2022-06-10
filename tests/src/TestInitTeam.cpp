/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** tests
*/

#include "tests.hpp"

TEST(TestTeamAlloc, Test1)
{
    team_t *team = team_create("team1");

    EXPECT_TRUE(team != nullptr);
    EXPECT_TRUE(uuid_is_null(team->id) == false);
    EXPECT_TRUE(strcmp(team->name, "team1") == 0);
    team_destroy(team);
}
