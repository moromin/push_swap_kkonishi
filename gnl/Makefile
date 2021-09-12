NAME	= libgnl.a
SRCS		= get_next_line.c get_next_line_utils.c
BONUS_SRCS	= get_next_line_bonus.c get_next_line_utils_bonus.c
OBJS		= $(SRC:%.c=%.o)
BONUS_OBJS	= $(BONUS_SRCS:%.c=%.o)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

bonus: $(BONUS_OBJS)
	@ar rc $(NAME) $(BONUS_OBJS)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus $(NAME)
