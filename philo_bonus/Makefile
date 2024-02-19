NAME = philo_bonus

ACT_DIR = acts/
ACT_FILES = act_eat.c \
	act_sleep.c \
	act_think.c
ACT_SRC = $(addprefix $(ACT_DIR), $(ACT_FILES))

INIT_DIR = init/
INIT_FILES = input_args.c \
	setup_data.c \
	setup_philos.c \
	validate_args.c
INIT_SRC = $(addprefix $(INIT_DIR), $(INIT_FILES))

UTILS_FT_DIR = ft/
UTILS_FT_FILES = ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_strlen.c
UTILS_FT_SRC = $(addprefix $(UTILS_FT_DIR), $(UTILS_FT_FILES))

UTIL_DIR = utils/
UTIL_FILES = $(UTILS_FT_SRC) \
	end_game.c \
	error_handlers.c \
	free_data.c \
	get_mutex.c \
	mutex_init.c \
	put_status.c \
	set_mutex.c \
	time_handlers.c
UTILS_SRC = $(addprefix $(UTIL_DIR), $(UTIL_FILES))

SRC_DIR = ./src/
SRC_FILES = $(ACT_SRC) \
	$(INIT_SRC) \
	$(UTILS_SRC) \
	game.c \
	main.c \
	monitoring.c \
	unit_philo.c
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

INCLUDES = -I ./include/
CFLAGS = -Wall -Wextra -Werror
TESTFLAGS = -g -fsanitize=address
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	CC = gcc
else
	CC = cc
endif

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC) $(UTIL) -o $(NAME)

test: $(SRC)
	$(CC) $(CFLAGS) $(TESTFLAGS) $(INCLUDES) $(SRC) $(UTIL) -o $(NAME)

clean:
	rm -rf $(NAME).dSYM

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all test clean fclean re