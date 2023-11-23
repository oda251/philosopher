NAME = philo
SRC_FILES = main.c \
	philo.c \
	philo_actions.c \
	init_data.c
UTIL_FILES = ft_atoi.c \
	ft_strlen.c \
	free_philo.c \
	put_status.c \
	error_handlers.c \
	ft_free.c \
	ft_mutex_init.c \
	count_done.c \
	handle_mutex.c \
	convert_time.c \
	mutex_destroy.c \
	get_current_ms.c
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