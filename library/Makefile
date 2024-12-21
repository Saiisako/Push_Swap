NAME = libft.a

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRCS	=		ft_split.c ft_atoi.c ft_isalpha.c ft_isdigit.c \
			ft_iswhitespace.c printf/ft_printf.c printf/printf_utils.c\
			ft_error.c ft_calloc.c ft_strlen.c ft_itoa.c ft_strdup.c\
			ft_putchar_fd.c ft_putstr_fd.c ft_bzero.c \

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

.c.o:
	cc $(FLAGS) -c $< -o $@
all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
