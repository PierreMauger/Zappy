/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** tests
*/

#include "tests.hpp"

SimulateCommand::SimulateCommand(void)
{
    args_t *args = init_args();

    args->height = 3;
    args->width = 3;
    args->teams = (char **)calloc(2, sizeof(char *));
    args->teams[0] = strdup("team1");

    this->core = core_create();
    core_init(core, args);
    list_push_data(core->game->trantorians, trantorian_create((team_t *)this->core->game->teams->head->data, 1, 1));

    destroy_args(args);

    this->client = client_create(0);
    this->client->trantorian = (trantorian_t *)this->core->game->trantorians->head->data;
    this->client->type = CLI_GUI;
}

SimulateCommand::~SimulateCommand(void)
{
    client_destroy(this->client);
    core_destroy(this->core);
}

void SimulateCommand::startTest(void)
{
    pipe(this->pipefd);
    this->client->sock->fd = this->pipefd[1];

    FD_SET(pipefd[1], &writefds);
}

void SimulateCommand::endTest(void)
{
    char buffer[1024] = {0};

    nlib_commands_update(this->core->server->commands_to_send, &this->writefds);
    read(pipefd[0], buffer, 1024);

    this->res = buffer;

    close(pipefd[0]);
    close(pipefd[1]);
}

std::string SimulateCommand::getRes(void)
{
    return this->res;
}

core_t *SimulateCommand::getCore(void)
{
    return this->core;
}

client_t *SimulateCommand::getClient(void)
{
    return this->client;
}
