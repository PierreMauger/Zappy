##
## EPITECH PROJECT, 2022
## Base
## File description:
## Lib Makefile
##

#################### PATH #####################
PATH_NLIB			=	./nlib/

PATH_LIST	=	./list/


################# COMPILATION #################
all:
	make -C	$(PATH_NLIB)
	make -C	$(PATH_LIST)

re:	fclean all

clean:
	@(make clean -C $(PATH_NLIB)) > /dev/null
	@(make clean -C $(PATH_LIST)) > /dev/null

fclean:	clean
	@(make fclean -C $(PATH_NLIB)) > /dev/null
	@(make fclean -C $(PATH_LIST)) > /dev/null
