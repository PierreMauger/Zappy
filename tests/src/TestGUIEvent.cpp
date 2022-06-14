/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** tests
*/

#include "tests.hpp"

TEST(TestGUIProtocol, pnw)
{
    SimulateCommand sc;
    char *buff = nullptr;

    sc.startTest();
    command_pnw(sc.getCore(), sc.getClient()->trantorian);
    sc.endTest();

    ASSERT_TRUE(asprintf(&buff, "pnw #%s %ld %ld %d  %ld %s\n",
        sc.getClient()->trantorian->uuid,
        sc.getClient()->trantorian->x,
        sc.getClient()->trantorian->y,
        (int)sc.getClient()->trantorian->direction,
        sc.getClient()->trantorian->level,
        sc.getClient()->trantorian->team->name) != -1);

    ASSERT_TRUE(sc.getRes() == buff);
}
