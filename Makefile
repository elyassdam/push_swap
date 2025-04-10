# =========================
#       MAKEFILE
# =========================

NAME = ft_push_swap

# ===== COMPILER & FLAGS =====
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I. -I./libft

# ===== SOURCE FILES =====
SRC = moves/rules.c \
	  moves/rules_2.c \
	  moves/ft_lstadd_back_swap.c \
	  ft_push_swap.c

OBJ = $(SRC:.c=.o)

# ===== LIBFT CONFIG =====
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# ===== RULES =====
all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
