NAME =push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror 
RM = rm -rf 
SRC = $(wildcard Mandatory/*.c )
SRCB = $(wildcard Bonus/*.c )
OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)
all: $(NAME) $(OBJ)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME) 

%.o: %.c Mandatory/push_swap.h
		$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJB)
	$(CC) $(OBJB) $(CFLAGS) -o  checker #-fsanitize=address

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)
		$(RM) $(OBJB) checker

re: fclean all  bonus

.PHONY: clean
