NAME = philo
SRC_FILES = main.c \
	philo.c \
	free_philo.c \
	init_datas.c \
	put_status.c
UTIL_FILES = ft_atoi.c \
	ft_strlen.c \
	error_handlers.c \
	ft_free.c \
	ft_mutex_init.c
SRC_DIR = ./src/
UTIL_DIR = $(SRC_DIR)utils/
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
UTIL = $(addprefix $(UTIL_DIR), $(UTIL_FILES))
INCLUDES = -I ./include/
CFLAGS = -Wall -Wextra -Werror
SANITIZE = -fsanitize=address
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	CC = gcc
else
	CC = cc
endif

all: $(NAME)

$(NAME): $(SRC) $(UTIL)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC) $(UTIL) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re