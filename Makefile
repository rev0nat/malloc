SRC_PATH = src/

SRC_NAME = main.c\

OBJ_PATH = build/

CPPFLAGS = -I include -I libft

LDLIBS = libft/libft.a

NAME = 

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all:$(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) -fPIC $^ $(LDLIBS) -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -DFOO -o $@ -c $<

clean:
	rm -fv $(OBJ)
	make clean -C libft
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	make fclean -C libft
	rm -fv $(NAME)

re: fclean all

norme:
	norminette src/*
	norminette libft/**.[ch]
	norminette include/*.h
.PHONY: all, clean, fclean, re