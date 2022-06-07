##
## EPITECH PROJECT, 2022
## Base
## File description:
## Main Makefile
##

##################### SRC #######################
SRC				=

SRC				+=	./src/main.c

SRC_TEST		=

#################### NAMES ######################
NAME			=	zappy_server

NAME_TEST		=	unit_tests


##################### OBJ #######################
OBJ				=	$(SRC:.c=.o)

OBJ_TEST		=	$(SRC_TEST:.c=.o)


##################### FLAGS #####################
INCLUDES		=	-I include -I ../include

LIBS			=	-L ../libs -llist -lnlib

CFLAGS			=	$(INCLUDES) $(LIBS) -Wall -Wextra -W -fPIC

CFLAGS_TEST		=	--coverage -lcriterion

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

fclean:	clean
	@rm -f $(NAME)
	@rm -f ../$(NAME)
	@(rm -f $(NAME) $(NAME_TEST)) > /dev/null
	@(rm -rf tests/coverage) > /dev/null

unit_tests:	$(OBJ_TEST)
	gcc -o $(NAME_TEST) $(OBJ_TEST) $(SRC) $(CFLAGS_TEST) $(CFLAGS)
	./$(NAME_TEST)

tests_run:	clean unit_tests

gcovr:	tests_run
	@gcovr --exclude tests
	@gcovr --exclude tests --branch

gen_html:	unit_tests
	@(mkdir -p tests/coverage) > /dev/null
	@(lcov -c -d . --output-file tests/coverage/lcov) > /dev/null
	@(genhtml tests/coverage/lcov --output-directory tests/coverage) > /dev/null

html_run:	gen_html
	@(firefox tests/coverage/index.html) > /dev/null
