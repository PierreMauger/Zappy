##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

all:
	make -C ./server
	make -C ./ai
	make -C ./gui

server:
	make -C ./server

ai:
	make -C ./ai

gui:
	make -C ./gui

clean:
	make clean -C ./server
	make clean -C ./ai
	make clean -C ./gui

fclean: clean
	make fclean -C ./server
	make fclean -C ./ai
	make fclean -C ./gui

re: fclean all
