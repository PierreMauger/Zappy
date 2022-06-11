##
## EPITECH PROJECT, 2022
## Base
## File description:
## Main Makefile
##

##################### SRC #######################
SRC				=	./src/init_client.c				\
					./src/create_client.c			\
					./src/parse_ret.c				\
					./src/send_message.c 			\

SRC				+=	./src/main.c

#################### NAMES ######################
NAME			=	zappy_ai

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
