##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRCS =  src/main.c				\

OBJS = $(SRCS:.c=.o)

CDEBUG = -g

CWARN = -W -Wall -Wextra

CFLAGS  = -L ../nlib/ -lmy -I ../include -g $(CWARN)

NAME = ./zappy_ai

all : $(NAME)

$(NAME) : $(OBJS)
		make -C ../nlib/
		gcc -o ../$(NAME) $(OBJS) $(CFLAGS)
		make fclean -C ../nlib/

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f ../$(NAME)

re : fclean all
