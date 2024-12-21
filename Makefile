NAME = push_swap

LIBRARY_DIR = ./library
LIBRARY = $(LIBRARY_DIR)/libft.a

SRCS = push_swap.c ft_list.c ft_rules.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBRARY)
	cc -Wall -Wextra -Werror $(OBJS) $(LIBRARY) -o $(NAME)

$(LIBRARY):
	make -C $(LIBRARY_DIR)

.c.o:
	cc -Wall -Wextra -Werror -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C $(LIBRARY_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBRARY_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
