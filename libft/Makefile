NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g 

# Fuentes principales
SRC = ft_atoi.c ft_itoa.c ft_putnbr_fd.c ft_strlcpy.c ft_toupper.c \
	ft_bzero.c ft_memchr.c ft_putstr_fd.c ft_strlen.c ft_strnstr.c\
	ft_calloc.c ft_memcmp.c ft_split.c ft_strmapi.c \
	ft_isalnum.c ft_memcpy.c ft_strchr.c ft_strncmp.c \
	ft_isalpha.c ft_memmove.c ft_strdup.c ft_strrchr.c \
	ft_isascii.c ft_memset.c ft_striteri.c ft_strtrim.c \
	ft_isdigit.c ft_putchar_fd.c ft_strjoin.c ft_substr.c \
	ft_isprint.c ft_putendl_fd.c ft_strlcat.c ft_tolower.c \
	ft_printf.c ft_putchar.c ft_putnbr.c ft_putnbru.c ft_putstr.c \
	ft_putnbr_base.c  ft_ptr.c ft_converter.c


# Objetos principales y bonus
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

# Objetivo principal
all: $(NAME)

# Creación de la librería
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Compilación de archivos .c a .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para compilar bonus
bonus: $(OBJ) $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ) $(OBJ_BONUS)

# Limpieza de archivos intermedios
clean:
	rm -f $(OBJ) $(OBJ_BONUS)

# Limpieza total (incluyendo la librería)
fclean: clean
	rm -f $(NAME)

# Reconstrucción total
re: fclean all
