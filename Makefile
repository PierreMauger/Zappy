##
## EPITECH PROJECT, 2022
## Base
## File description:
## Main Makefile
##

#################### PATH #####################
PATH_LIBS		=	./libs/

PATH_AI			=	./ai/

PATH_SERVER		=	./server/

PATH_GUI		=	./gui/


################# COMPILATION #################
all:
	make -C	$(PATH_LIBS)
	make -C	$(PATH_AI)
	make -C	$(PATH_SERVER)
	make -C	$(PATH_GUI)

re:	fclean all

clean:
	@(make clean -C $(PATH_LIBS)) > /dev/null
	@(make clean -C $(PATH_AI)) > /dev/null
	@(make clean -C $(PATH_SERVER)) > /dev/null
	@(make clean -C $(PATH_GUI)) > /dev/null

fclean:	clean
	@(make fclean -C $(PATH_LIBS)) > /dev/null
	@(make fclean -C $(PATH_AI)) > /dev/null
	@(make fclean -C $(PATH_SERVER)) > /dev/null
	@(make fclean -C $(PATH_GUI)) > /dev/null

debug:
	@(make -C $(PATH_LIBS)) > /dev/null
	@(make debug -C $(PATH_AI)) > /dev/null
	@(make debug -C $(PATH_SERVER)) > /dev/null
	@(make debug -C $(PATH_GUI)) > /dev/null

unit-tests: all
	./utils/run_tests.sh

install-raylib:
	./utils/install_raylib.sh
