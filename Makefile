# =========================
#       MAKEFILE (Raíz del proyecto)
# =========================

NAME = ft_push_swap

# ===== COMPILER & FLAGS =====
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

# ===== SOURCE FILES =====
SRC =   src/moves/rules.c \
		src/moves/rules_2.c \
		src/ft_push_swap.c \
		src/sort/sort_three.c \
		src/sort/sort_five.c 

OBJ = $(SRC:.c=.o)

# ===== LIBFT CONFIG =====
LIBFT_DIR = libft
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME)

# ===== RULES =====
all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
