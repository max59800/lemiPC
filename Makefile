NAME=		lemipc

SRC=		main.c

OBJ=		$(SRC:.c=.o)

all:		$(OBJ)
		cc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all