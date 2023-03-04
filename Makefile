##
## EPITECH PROJECT, 2023
## Sudoki
## File description:
## Makefile
##

all:
	make -C ./solver
	make -C ./generator

clean:
	make -C clean ./solver
	make -C clean ./generator

fclean:	clean
	make -C fclean ./solver
	make -C fclean ./generator

debug:
	make -C debug ./solver
	make -C debug ./generator

re:
	make -C re ./solver
	make -C re ./generator

.PHONY:	all re clean fclean debug
