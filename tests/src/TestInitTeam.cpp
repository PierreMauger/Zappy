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

TEST(TestTeamInit, Basic)
{
    const char *teams[] = {
        "team1",
        "team2",
        "team3",
        "team4",
        "team5",
        "team6",
        "team7",
        "team8",
        "team9",
        "team10",
        NULL
    };
    list_t *teams_list = list_create();

    ASSERT_TRUE(teams_list != nullptr);
    EXPECT_TRUE(team_init(teams_list, (char **)teams) == SUCCESS);
    list_destroy(teams_list, (void (*)(void *))team_destroy);
}

TEST(TestTeamInit, SameTeam)
{
    const char *teams[] = {
        "team1",
        "team1",
        "team2",
        NULL
    };
    list_t *teams_list = list_create();

    ASSERT_TRUE(teams_list != nullptr);
    EXPECT_TRUE(team_init(teams_list, (char **)teams) == ERROR);
    list_destroy(teams_list, (void (*)(void *))team_destroy);
}

TEST(TestTeamInit, NoTeam)
{
    list_t *teams_list = list_create();

    ASSERT_TRUE(teams_list != nullptr);
    EXPECT_TRUE(team_init(teams_list, NULL) == ERROR);
    list_destroy(teams_list, (void (*)(void *))team_destroy);
}
