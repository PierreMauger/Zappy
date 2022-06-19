/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** tests
*/

#include "tests.hpp"

static CommandFixture sc;

TEST(TestGameCalcDirSound, Basic1)
{
    core_t *core = sc.getCore();
    pos_t pos_a = {3, 9};
    pos_t pos_b = {7, 6};

    core->game->map->width = 10;
    core->game->map->height = 10;

    EXPECT_EQ(game_calc_direction(core->game->map, DIR_UP, &pos_b, &pos_a),
        TILE_EIGHT);

    core->game->map->width = 0;
    core->game->map->height = 0;
}

TEST(TestGameCalcDirSound, Basic2)
{
    core_t *core = sc.getCore();
    pos_t pos_a = {3, 9};
    pos_t pos_b = {7, 6};

    core->game->map->width = 10;
    core->game->map->height = 10;

    EXPECT_EQ(game_calc_direction(core->game->map, DIR_RIGHT, &pos_b, &pos_a),
        TILE_TWO);

    core->game->map->width = 0;
    core->game->map->height = 0;
}

TEST(TestGameCalcDirSound, Basic3)
{
    core_t *core = sc.getCore();
    pos_t pos_a = {3, 9};
    pos_t pos_b = {7, 6};

    core->game->map->width = 10;
    core->game->map->height = 10;

    EXPECT_EQ(game_calc_direction(core->game->map, DIR_DOWN, &pos_b, &pos_a),
        TILE_FOUR);

    core->game->map->width = 0;
    core->game->map->height = 0;
}

TEST(TestGameCalcDirSound, Basic4)
{
    core_t *core = sc.getCore();
    pos_t pos_a = {3, 9};
    pos_t pos_b = {7, 6};

    core->game->map->width = 10;
    core->game->map->height = 10;

    EXPECT_EQ(game_calc_direction(core->game->map, DIR_LEFT, &pos_b, &pos_a),
        TILE_SIX);

    core->game->map->width = 0;
    core->game->map->height = 0;
}

TEST(TestGameCalcDirSound, Basic5)
{
    core_t *core = sc.getCore();
    pos_t pos_a = {3, 5};
    pos_t pos_b = {8, 6};

    core->game->map->width = 10;
    core->game->map->height = 10;

    EXPECT_EQ(game_calc_direction(core->game->map, DIR_UP, &pos_b, &pos_a),
        TILE_THREE);

    core->game->map->width = 0;
    core->game->map->height = 0;
}

TEST(TestGameCalcDirSound, Basic6)
{
    core_t *core = sc.getCore();
    pos_t pos_a = {3, 6};
    pos_t pos_b = {8, 5};

    core->game->map->width = 10;
    core->game->map->height = 10;

    EXPECT_EQ(game_calc_direction(core->game->map, DIR_UP, &pos_b, &pos_a),
        TILE_THREE);

    core->game->map->width = 0;
    core->game->map->height = 0;
}

TEST(TestGameCalcDirSound, Basic7)
{
    core_t *core = sc.getCore();
    pos_t pos_a = {3, 6};
    pos_t pos_b = {8, 5};

    core->game->map->width = 10;
    core->game->map->height = 10;

    EXPECT_EQ(game_calc_direction(core->game->map, DIR_DOWN, &pos_b, &pos_a),
        TILE_SEVEN);

    core->game->map->width = 0;
    core->game->map->height = 0;
}

TEST(TestGameCalcDirSound, Basic8)
{
    core_t *core = sc.getCore();
    pos_t pos_a = {5, 8};
    pos_t pos_b = {6, 3};

    core->game->map->width = 10;
    core->game->map->height = 10;

    EXPECT_EQ(game_calc_direction(core->game->map, DIR_UP, &pos_b, &pos_a),
        TILE_FIVE);

    core->game->map->width = 0;
    core->game->map->height = 0;
}

TEST(TestGameCalcDirSound, Basic9)
{
    core_t *core = sc.getCore();
    pos_t pos_a = {6, 3};
    pos_t pos_b = {5, 8};

    core->game->map->width = 10;
    core->game->map->height = 10;

    EXPECT_EQ(game_calc_direction(core->game->map, DIR_UP, &pos_b, &pos_a),
        TILE_ONE);

    core->game->map->width = 0;
    core->game->map->height = 0;
}

TEST(TestGameCalcDirSound, SameAxe1)
{
    core_t *core = sc.getCore();
    pos_t pos_a = {7, 9};
    pos_t pos_b = {7, 6};

    core->game->map->width = 10;
    core->game->map->height = 10;

    EXPECT_EQ(game_calc_direction(core->game->map, DIR_UP, &pos_b, &pos_a),
        TILE_FIVE);

    core->game->map->width = 0;
    core->game->map->height = 0;
}

TEST(TestGameCalcDirSound, SameAxe2)
{
    core_t *core = sc.getCore();
    pos_t pos_a = {7, 6};
    pos_t pos_b = {7, 9};

    core->game->map->width = 10;
    core->game->map->height = 10;

    EXPECT_EQ(game_calc_direction(core->game->map, DIR_UP, &pos_b, &pos_a),
        TILE_ONE);

    core->game->map->width = 0;
    core->game->map->height = 0;
}

TEST(TestGameCalcDirSound, SameAxe3)
{
    core_t *core = sc.getCore();
    pos_t pos_a = {6, 7};
    pos_t pos_b = {9, 7};

    core->game->map->width = 10;
    core->game->map->height = 10;

    EXPECT_EQ(game_calc_direction(core->game->map, DIR_UP, &pos_b, &pos_a),
        TILE_SEVEN);

    core->game->map->width = 0;
    core->game->map->height = 0;
}

TEST(TestGameCalcDirSound, SameAxe4)
{
    core_t *core = sc.getCore();
    pos_t pos_a = {9, 7};
    pos_t pos_b = {6, 7};

    core->game->map->width = 10;
    core->game->map->height = 10;

    EXPECT_EQ(game_calc_direction(core->game->map, DIR_UP, &pos_b, &pos_a),
        TILE_THREE);

    core->game->map->width = 0;
    core->game->map->height = 0;
}

TEST(TestCommandBroadCast, Basic)
{
    char *msg = strdup("MESSAGE");

    sc.startTest();
    broadcast_e(sc.getCore(), sc.getClient(), msg);
    sc.endTest();

    EXPECT_EQ(sc.getRes(), "ok\n");
    EXPECT_EQ(sc.getResOtherCli(), "message 4, MESSAGE\n");

    free(msg);
}
