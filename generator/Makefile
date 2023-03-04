SRC =	tools.c

OBJ =	$(SRC:%.c=obj/%.o)

MAIN =	main.c

OBJ_MAIN =	$(MAIN:%.c=obj/%.o)

CC =	gcc

CFLAGS =	-Wall -Wextra

CPPFLAGS =	-Iinclude

NAME =	lem_in

all:	$(NAME)

$(NAME): $(OBJ) $(OBJ_MAIN) $(LIB_NAME) $(LIB_LIST_NAME)
	$(CC) -o $(NAME) $(OBJ) $(OBJ_MAIN) $(LDFLAGS) $(LDLIBS)

clean:
	$(RM) $(OBJ) $(OBJ_MAIN)

fclean:	clean
	$(RM) $(NAME)

debug:	CFLAGS += -g
debug:	fclean all

obj/%.o: src/%.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

re:	fclean all

.PHONY:	all re clean fclean debug
