NAME = get_next_line
SRC = .
INC = .
OBJ = .
LIST_SRC = $(SRC)/main.c $(SRC)/get_next_line.c

LIST_OBJ = $(LIST_SRC:$(SRC)/%.c=$(OBJ)/%.o)
CFLAG = -Wall -Wextra -Werror
# CFLAG = -Wall -Wextra -Werror -g -O0
LIBFT = libft.a
LIBFTPATH = ./libft/
INC_LIBFTPATH  = $(LIBFTPATH)

all : $(NAME)

$(NAME) : $(LIST_SRC)
		make -C $(LIBFTPATH)
		gcc $(CFLAG) -I $(INC) -I $(INC_LIBFTPATH) $(LIST_SRC) -L$(LIBFTPATH) -lft -o $(NAME)

clean :
		make clean -C $(LIBFTPATH)
		/bin/rm -f  $(LIST_OBJ)

fclean : clean
		make fclean -C $(LIBFTPATH)
		/bin/rm -f $(NAME)

re : fclean all
