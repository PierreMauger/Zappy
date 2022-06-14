/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** tests
*/

#include "tests.hpp"

static core_t *core = NULL;
static client_t *client = NULL;

static void SetupElems(void)
{
    if (core != nullptr)
        return;
    args_t *args = init_args();
    args->height = 3;
    args->width = 3;
    args->teams = (char **)calloc(2, sizeof(char *));
    args->teams[0] = strdup("team1");
    core = core_create();
    core_init(core, args);
    list_push_data(core->game->trantorians, trantorian_create((team_t *)core->game->teams->head->data, 1, 1));
    ASSERT_TRUE(core->game != nullptr);
    client = client_create(0);
    client->trantorian = (trantorian_t *)core->game->trantorians->head->data;
}

static char *GenericTest(const char *command, void (*func)(core_t *, client_t *, char *))
{
    char *malloc_command = command ? strdup(command) : NULL;
    int pipefd[2];
    fd_set writefds = {0};

    SetupElems();

    pipe(pipefd);
    client->sock->fd = pipefd[1];

    FD_SET(pipefd[1], &writefds);

    func(core, client, malloc_command);
    free(malloc_command);
    nlib_commands_update(core->server->commands_to_send, &writefds);

    char buffer[1024] = {0};
    size_t nb_read = read(pipefd[0], buffer, 1024);

    close(pipefd[0]);
    close(pipefd[1]);
    return strdup(buffer);
}

TEST(TestGUIProtocol, msz)
{
    char *rep = GenericTest(NULL, command_msz);

    ASSERT_EQ(strcmp(rep, "msz 3 3\n"), 0);
}

TEST(TestGUIProtocol, bct1)
{
    GET_CELL(core->game->map, 0, 1)->food = 1;
    GET_CELL(core->game->map, 0, 1)->linemate = 2;
    GET_CELL(core->game->map, 0, 1)->deraumere = 3;
    GET_CELL(core->game->map, 0, 1)->sibur = 4;
    GET_CELL(core->game->map, 0, 1)->mendiane = 5;
    GET_CELL(core->game->map, 0, 1)->phiras = 6;
    GET_CELL(core->game->map, 0, 1)->thystame = 7;

    char *rep = GenericTest("0 1", command_bct);

    ASSERT_EQ(strcmp(rep, "bct 0 1 1 2 3 4 5 6 7\n"), 0);
}

TEST(TestGUIProtocol, bct2)
{
    GET_CELL(core->game->map, 2, 2)->food = 1;
    GET_CELL(core->game->map, 2, 2)->linemate = 2;
    GET_CELL(core->game->map, 2, 2)->deraumere = 3;
    GET_CELL(core->game->map, 2, 2)->sibur = 4;
    GET_CELL(core->game->map, 2, 2)->mendiane = 5;
    GET_CELL(core->game->map, 2, 2)->phiras = 6;
    GET_CELL(core->game->map, 2, 2)->thystame = 7;

    char *rep = GenericTest("2 2", command_bct);

    ASSERT_EQ(strcmp(rep, "bct 2 2 1 2 3 4 5 6 7\n"), 0);
}

TEST(TestGUIProtocol, bctIncorrect1)
{
    char *rep = GenericTest("-10 1", command_bct);

    ASSERT_EQ(strcmp(rep, "sbp\n"), 0);
}

TEST(TestGUIProtocol, bctIncorrect2)
{
    char *rep = GenericTest("qkfdsmekd", command_bct);

    ASSERT_EQ(strcmp(rep, "sbp\n"), 0);
}

TEST(TestGUIProtocol, mct)
{
    char *rep = GenericTest(NULL, command_mct);

    ASSERT_EQ(strcmp(rep,
        "bct 0 0 0 0 0 0 0 0 0\n"
        "bct 1 0 0 0 0 0 0 0 0\n"
        "bct 2 0 0 0 0 0 0 0 0\n"
        "bct 0 1 1 2 3 4 5 6 7\n"
        "bct 1 1 0 0 0 0 0 0 0\n"
        "bct 2 1 0 0 0 0 0 0 0\n"
        "bct 0 2 0 0 0 0 0 0 0\n"
        "bct 1 2 0 0 0 0 0 0 0\n"
        "bct 2 2 1 2 3 4 5 6 7\n"
    ), 0);
}

TEST(TestGUIProtocol, tna)
{
    char *rep = GenericTest(NULL, command_tna);

    ASSERT_EQ(strcmp(rep, "tna team1\n"), 0);
}

TEST(TestGUIProtocol, ppo)
{
    char *rep = GenericTest(client->trantorian->uuid, command_ppo);
    char *expected = NULL;

    asprintf(&expected, "ppo %s %ld %ld %d\n",
        client->trantorian->uuid,
        client->trantorian->x,
        client->trantorian->y,
        (int)client->trantorian->direction
    );
    ASSERT_EQ(strcmp(rep, expected), 0);
    free(expected);
}

TEST(TestGUIProtocol, ppoIncorrect)
{
    char *rep = GenericTest("scsq", command_ppo);

    ASSERT_EQ(strcmp(rep, "sbp\n"), 0);
}

TEST(TestGUIProtocol, plv)
{
    char *rep = GenericTest(client->trantorian->uuid, command_plv);
    char *expected = NULL;

    asprintf(&expected, "plv %s %ld\n",
        client->trantorian->uuid,
        client->trantorian->level
    );
    ASSERT_EQ(strcmp(rep, expected), 0);
    free(expected);
}

TEST(TestGUIProtocol, plvIncorrect)
{
    char *rep = GenericTest("", command_plv);

    ASSERT_EQ(strcmp(rep, "sbp\n"), 0);
}

TEST(TestGUIProtocol, pin)
{
    client->trantorian->inventory->food = 1;
    client->trantorian->inventory->linemate = 2;
    client->trantorian->inventory->deraumere = 3;
    client->trantorian->inventory->sibur = 4;
    client->trantorian->inventory->mendiane = 5;
    client->trantorian->inventory->phiras = 6;
    client->trantorian->inventory->thystame = 7;

    char *rep = GenericTest(client->trantorian->uuid, command_pin);
    char *expected = NULL;

    asprintf(&expected, "pin %s %ld %ld %ld %ld %ld %ld %ld %ld %ld\n",
        client->trantorian->uuid,
        core->game->map->width, core->game->map->height,
        client->trantorian->inventory->food,
        client->trantorian->inventory->linemate,
        client->trantorian->inventory->deraumere,
        client->trantorian->inventory->sibur,
        client->trantorian->inventory->mendiane,
        client->trantorian->inventory->phiras,
        client->trantorian->inventory->thystame
    );
    ASSERT_EQ(strcmp(rep, expected), 0);
    free(expected);
}

TEST(TestGUIProtocol, pinIncorrect)
{
    char *rep = GenericTest("", command_pin);

    ASSERT_EQ(strcmp(rep, "sbp\n"), 0);
}

TEST(TestGUIProtocol, sgt)
{
    char *rep = GenericTest(NULL, command_sgt);
    char *expected = NULL;

    asprintf(&expected, "sgt %ld\n",
        core->game->freq
    );
    ASSERT_EQ(strcmp(rep, expected), 0);
    free(expected);
}
