# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malee <malee@42mail.sutd.edu.sg>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 23:01:22 by malee             #+#    #+#              #
#    Updated: 2024/03/18 23:03:29 by malee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

INCLUDES = includes

SRCS = srcs/

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	make -C Libft
	mv ./Libft/libft.a ./
	make fclean -C Libft
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -I$(INCLUDES) -ILibft libft.a

clean:
	rm -rf $(OBJECTS) $(NAME).a libft.a

fclean: clean
	rm -rf $(NAME)

re: fclean all