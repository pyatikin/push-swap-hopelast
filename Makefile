NAME		=	push_swap

CC			=	gcc

CFLAGS		=	

SRC			=	push_swap.c stack2.c stack.c libft/ft_atoi.c libft/ft_isdigit.c command1.c sorting.c libft/ft_strlen.c extra.c \
				for_sorting1.c for_sorting2.c

OBJ			=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) Makefile
	$(CC) $(OBJ) push_swap.h -o $(NAME)
	
%.o: %.c
	$(CC) -c $< -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

norm:
	norminette