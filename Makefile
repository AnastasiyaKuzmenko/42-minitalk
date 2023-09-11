# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 13:23:14 by akuzmenk          #+#    #+#              #
#    Updated: 2023/04/12 11:13:51 by akuzmenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER := server
CLIENT := client
FLAGS := -Wall -Wextra -Werror
PRINTF_DIR := ./ft_printf
PRINTF_LIB := $(PRINTF_DIR)/libftprintf.a

SRCS_SERVER := server.c
SRCS_CLIENT := client.c

OBJS_SERVER := $(SRCS_SERVER:.c=.o)
OBJS_CLIENT := $(SRCS_CLIENT:.c=.o)

all: $(SERVER) $(CLIENT)
	
$(SERVER): $(SRCS_SERVER)
	make -sC $(PRINTF_DIR)
	cc $(FLAGS) -c $(SRCS_SERVER)
	cc $(FLAGS) $(SRCS_SERVER) -o $(SERVER) -L. $(PRINTF_LIB)

$(CLIENT): $(SRCS_CLIENT)
	make -sC $(PRINTF_DIR)
	cc $(FLAGS) -c $(SRCS_CLIENT)
	cc $(FLAGS) $(SRCS_CLIENT) -o $(CLIENT) -L. $(PRINTF_LIB)
clean:
	make clean -sC $(PRINTF_DIR)
	rm -f $(OBJS_SERVER)
	rm -f $(OBJS_CLIENT)

fclean: clean
	make fclean -sC $(PRINTF_DIR)
	rm -f $(SERVER)
	rm -f $(CLIENT)
	
re: fclean all

.PHONY: clean fclean re