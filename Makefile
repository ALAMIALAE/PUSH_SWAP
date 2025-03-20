CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

NAME = push_swap
NAME_BONUS = checker

SRCS = push_swap.c ft_split.c push.c \
	rotate.c swap.c reverse_rotate.c sort.c sort_utils.c \
	algo.c algo_utils.c parse.c parsing_utils.c

BONUS_SRCS = bonus/parse_bonus.c	bonus/parsing_utils_bonus.c	bonus/split_bonus.c	bonus/push_swap_bonus.c \
	bonus/get_next_line_utils.c	bonus/get_next_line.c	bonus/swap_bonus.c	bonus/rotate_bonus.c \
	bonus/reverse_rotate_bonus.c	bonus/push_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(NAME_BONUS): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(NAME_BONUS)

all: $(NAME)

bonus: $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all