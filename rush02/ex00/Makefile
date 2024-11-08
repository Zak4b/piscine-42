# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asene <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/04 22:29:44 by asene             #+#    #+#              #
#    Updated: 2024/08/04 22:29:45 by asene            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush02

SOURCES = main.c \
	ft_putstr.c ft_check_char.c ft_strings.c ft_putnbr_char.c \
	ft_split.c dict.c dict_parser.c dict_print.c ft_dict_sort.c \
	utils.c

OBJECTS = $(SOURCES:.c=.o)

FLAGS = -Wall -Wextra -Werror

%.o: %.c
	cc $(FLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	cc $(FLAGS) -o $(NAME) $(OBJECTS)

all: $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)
	
re: fclean all