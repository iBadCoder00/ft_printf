CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = exlibft.c format_utils.c ft_printaddr.c ft_printchar.c ft_printf.c ft_printhex.c ft_printint.c ft_printstr.c ft_printuint.c utils.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

SRC_DIR = src

OBJ_DIR = obj

INCLUDE = include

all: $(NAME)

bonus: all

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(OBJ_DIR): 
	mkdir $(OBJ_DIR)

main: 
	$(CC) $(CFLAGS) -I $(INCLUDE) main.c $(NAME)
	./a.out

clean:
	rm -rf obj/

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
