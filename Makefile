NAME =push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
SRC = check_sort.c ft_atoi.c ft_putstr_fd.c ft_split.c push_moves.c reverse_rotate_moves.c\
rotate_moves.c sort_stack.c swap_moves.c main.c
OBJ = $(SRC:.c=.o)

all: $(NAME) $(OBJ)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME) 

%.o: %.c push_swap.h
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all 

.PHONY: clean
