NAME = push_swap

LIBRARY_DIR = ./library
LIBRARY = $(LIBRARY_DIR)/libft.a
FLAGS = -Wall -Werror -Wextra -g #-fsanitize=address
SRCS =	push_swap.c list.c free.c bubblesort.c\
		instructions/push.c instructions/rotate.c instructions/reverse.c instructions/swap.c\
		algo/algo.c algo/algo_3.c algo/algo_5.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBRARY)
	cc $(FLAGS) $(OBJS) $(LIBRARY) -o $(NAME)

$(LIBRARY):
	make -C $(LIBRARY_DIR)

.c.o:
	cc $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C $(LIBRARY_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBRARY_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
