# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/20 12:00:34 by akuzmenk          #+#    #+#              #
#    Updated: 2023/01/16 10:41:14 by akuzmenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

SRCS = ft_printf.c \
		ft_print_str.c \
		ft_print_ptr.c \
		ft_print_unsigned.c \
		ft_print_nbr.c \
		ft_print_hexadecimal.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT)
	make -C $(LIBFT_DIR)
	cp $(LIBFT_LIB) $(NAME)
	cc $(FLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJS)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)
	
re: fclean all
