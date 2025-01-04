NAME = push_swap
BONUS_NAME = checker
LIBRARY_DIR = ./library
LIBRARY = $(LIBRARY_DIR)/libft.a
FLAGS = -Wall -Wextra -Werror #-g #-fsanitize=address

SRCS =	push_swap.c utils/free.c utils/list.c \
		instructions/push.c instructions/rotate.c instructions/reverse.c instructions/swap.c \
		algo/algo.c algo/algo_3.c algo/algo_5.c algo/algo_update.c algo/algo_utils.c algo/bubblesort.c\

BONUS_SRCS =	checker.c utils/free.c utils/list.c \
				instructions/push.c instructions/rotate.c instructions/reverse.c instructions/swap.c \
				algo/algo.c algo/algo_3.c algo/algo_5.c algo/algo_update.c algo/algo_utils.c algo/bubblesort.c\

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJS) $(LIBRARY)
	cc $(FLAGS) $(OBJS) $(LIBRARY) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBRARY)
	cc $(FLAGS) $(BONUS_OBJS) $(LIBRARY) -o $(BONUS_NAME)

$(LIBRARY):
	make -C $(LIBRARY_DIR)

.c.o:
	cc $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	make -C $(LIBRARY_DIR) clean

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	make -C $(LIBRARY_DIR) fclean
	rm -rf push_swap_tester checker_linux

re: fclean all

tester:
	@git clone "https://github.com/SimonCROS/push_swap_tester.git"
	@wget "https://cdn.intra.42.fr/document/document/28289/checker_linux"
	chmod 777 checker_linux
	cd push_swap_tester && make

.PHONY: all clean fclean re bonus
