NAME = philo
SRC_FILES = main.c \
	philo.c \
	free_philo.c
UTIL_FILES = ft_atoi.c \
	ft_strlen.c \
	error_handlers.c \
	ft_free.c
SRC_DIR = ./src/
UTIL_DIR = $(SRC_DIR)utils/
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
UTIL = $(addprefix $(UTIL_DIR), $(UTIL_FILES))
INCLUDES = -I ./include/
CC = cc
CFLAGS = -Wall -Wextra -Werror
SANITIZE = -fsanitize=address

all: $(NAME)

$(NAME): $(SRC) $(UTIL)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC) $(UTIL) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re