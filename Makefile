NAME		= push_swap
# Change checker name!!!
BONUS_NAME	= my_checker
SRCS		= 	ps_main.c node.c node_checker.c arg_checker.c \
				branch_until_six.c branch_until_three.c branch_over_six.c \
				compression_1.c compression_2.c \
				quick_sort_stack.c \
				action_main.c \
				sort_utils.c 
BONUS_SRCS	= 	checker_main.c node.c node_checker.c arg_checker.c \
				branch_until_six.c branch_until_three.c branch_over_six.c \
				compression_1.c compression_2.c \
				quick_sort_stack.c \
				action_main.c sort_utils.c \
				checker_command.c checker_action.c
NEO_SRCS	=	ps_main.c node.c node_checker.c arg_checker.c \
				branch_until_six.c branch_until_three.c neo_branch_over_six.c \
				compression_1.c compression_2.c \
				neo_quick_sort_stack.c \
				action_main.c \
				neo_sort_utils.c 
OBJS		= $(SRCS:%.c=%.o)
BONUS_OBJS	= $(BONUS_SRCS:%.c=%.o)
NEO_OBJS	= $(NEO_SRCS:%.c=%.o)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
LIBFT_PATH	= ./libft/
GNL_PATH	= ./gnl/

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

bonus: $(BONUS_OBJS) $(NAME)
	make bonus -C $(GNL_PATH)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -L$(LIBFT_PATH) -lft -L$(GNL_PATH) -lgnl -o $(BONUS_NAME)

clean:
	make clean -C $(LIBFT_PATH)
	rm -f $(OBJS) $(BONUS_OBJS) $(NEO_OBJS)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	make fclean -C $(GNL_PATH)
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

# TODO
neo: $(NEO_OBJS)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(NEO_OBJS) -L$(LIBFT_PATH) -lft -o $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus $(NAME)
