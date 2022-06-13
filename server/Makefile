##
## EPITECH PROJECT, 2022
## Base
## File description:
## Main Makefile
##

##################### SRC #######################
SRC				=	src/manage_struct/manage_client.c						\
					src/manage_struct/manage_core.c							\
					src/manage_struct/manage_game.c							\
					src/manage_struct/manage_inventory.c					\
					src/manage_struct/manage_map.c							\
					src/manage_struct/manage_server.c						\
					src/manage_struct/manage_team.c							\
					src/manage_struct/manage_trantorian.c					\
					src/utils/parse_params.c								\
					src/utils/set_fds.c										\
					src/server_handling/server_handling.c					\
					src/server_handling/start_server.c						\
					src/client_handling/client_update.c						\
					src/client_handling/client_exec_command.c				\
					src/client_handling/commands/forward.c					\
					src/client_handling/commands/right.c					\
					src/client_handling/commands/left.c						\
					src/client_handling/commands/look.c						\
					src/client_handling/commands/inventory.c				\
					src/client_handling/commands/broadcast.c				\
					src/client_handling/commands/connect_nbr.c				\
					src/client_handling/commands/fork.c						\
					src/client_handling/commands/eject.c					\
					src/client_handling/commands/take.c						\
					src/client_handling/commands/set.c						\
					src/client_handling/commands/incantation.c				\
					src/utils/command_utils.c							\

SRC				+=	./src/main.c

#################### NAMES ######################
NAME			=	zappy_server

##################### OBJ #######################
OBJ				=	$(SRC:.c=.o)

##################### FLAGS #####################
INCLUDES		=	-I include -I ../include

LIBS			=	-L ../libs -llist -lnlib -luuid							\
					-Wl,-rpath=$(shell readlink -f "../libs/")				\

CFLAGS			=	$(INCLUDES) $(LIBS) -Wall -Wextra -W -fPIC

CFLAGS_DEBUG	=	-g


################## COMPILATION ##################
$(NAME):	$(OBJ)
	@(gcc $(OBJ) -o $(NAME) $(CFLAGS)) > /dev/null
	@(cp $(NAME) ../)

all:	$(NAME)

debug:	CFLAGS += $(CFLAGS_DEBUG)
debug:	re

re:	fclean all

clean:
	@(rm -f $(OBJ)) > /dev/null
	@find . -name "*.gcno" -delete
	@find . -name "*.gcda" -delete
	@find . -name "*.o" -delete
	@find . -name "*.so" -delete

fclean:	clean
	@rm -f $(NAME)
	@rm -f ../$(NAME)
	@(rm -f $(NAME)) > /dev/null
	@(rm -rf tests/coverage) > /dev/null
