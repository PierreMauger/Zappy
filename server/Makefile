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

SRC_MAIN		+=	./src/main.c

SRC_TEST		=

#################### NAMES ######################
NAME			=	zappy_server

NAME_TEST		=	libzappy_server.so


##################### OBJ #######################
OBJ				=	$(SRC:.c=.o)

OBJ_MAIN		=	$(SRC_MAIN:.c=.o)

OBJ_TEST		=	$(SRC_TEST:.c=.o)


##################### FLAGS #####################
INCLUDES		=	-I include -I ../include

LIBS			=	-L ../libs -llist -lnlib -luuid

CFLAGS			=	$(INCLUDES) $(LIBS) -Wall -Wextra -W -fPIC

CFLAGS_TEST		=	--shared

CFLAGS_DEBUG	=	-g


################## COMPILATION ##################
$(NAME):	$(OBJ) $(OBJ_MAIN)
	@(gcc $(OBJ) $(OBJ_MAIN) -o $(NAME) $(CFLAGS)) > /dev/null
	@(cp $(NAME) ../)

all:	$(NAME)

debug:	CFLAGS += $(CFLAGS_DEBUG)
debug:	re

re:	fclean all

clean:
	@(rm -f $(OBJ) $(OBJ_MAIN)) > /dev/null
	@find . -name "*.gcno" -delete
	@find . -name "*.gcda" -delete
	@find . -name "*.o" -delete
	@find . -name "*.so" -delete

fclean:	clean
	@rm -f $(NAME)
	@rm -f ../$(NAME)
	@rm -f ../libs/$(NAME_TEST)
	@(rm -f $(NAME) $(NAME_TEST)) > /dev/null
	@(rm -rf tests/coverage) > /dev/null

unit_tests:	$(OBJ_TEST)
	@(gcc $(OBJ) $(OBJ_MAIN) -o ../libs/$(NAME_TEST) $(CFLAGS)) > /dev/null
