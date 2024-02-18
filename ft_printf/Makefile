CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = $(filter-out main.c, $(wildcard *.c))

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

OBJ_DIR = obj


all: $(NAME)

bonus: all

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR): 
	mkdir $(OBJ_DIR)

main: 
	$(CC) $(CFLAGS) main.c $(NAME)
	./a.out

clean:
	rm -rf obj/

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
