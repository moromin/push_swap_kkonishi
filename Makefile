NAME		= push_swap
SRCS		= 	main.c node.c node_checker.c arg_checker.c \
				branch_until_six.c branch_until_three.c branch_over_six.c \
				compression_1.c compression_2.c \
				action_main.c
# BONUS_SRCS	= get_next_line_bonus.c get_next_line_utils_bonus.c
OBJS		= $(SRCS:%.c=%.o)
# BONUS_OBJS	= $(BONUS_SRCS:%.c=%.o)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
LIBFT_PATH	= ./libft/

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) -I $(LIBFT_PATH) $(OBJS) -L$(LIBFT_PATH) -lft -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

bonus: $(BONUS_OBJS)
	ar rc $(NAME) $(BONUS_OBJS)
	ranlib $(NAME)

clean:
	make clean -C $(LIBFT_PATH)
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus $(NAME)
