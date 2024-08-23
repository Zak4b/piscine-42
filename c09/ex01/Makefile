NAME = libft.a
SOURCES = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
OBJECTS = $(SOURCES:.c=.o)
FLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJECTS)
	ar -src $(NAME) $(OBJECTS)
all: $(NAME)
clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME)
re: fclean all