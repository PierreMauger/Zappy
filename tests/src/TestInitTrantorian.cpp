/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** tests
*/

#include "tests.hpp"

TEST(TestTrantorianAlloc, Test1)
{
    team_t *team = team_create("team1");
    trantorian_t *trantorian = nullptr;

    ASSERT_TRUE(team != nullptr);
    trantorian = trantorian_create(team->id, 0, 0);
    EXPECT_TRUE(trantorian != nullptr);
    EXPECT_TRUE(uuid_compare(team->id, trantorian->id_team) == false);
    trantorian_destroy(trantorian);
    team_destroy(team);
}
