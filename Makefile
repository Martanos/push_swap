# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malee <malee@42mail.sutd.edu.sg>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 23:01:22 by malee             #+#    #+#              #
#    Updated: 2024/05/10 13:45:23 by malee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Os -Wall -Wextra -Werror -g -I$(LIBFT_DIR) -I$(INCLUDES_DIR) -I$(SRCS_DIR)
INCLUDES_DIR = includes
LIBFT_DIR = Libft
SRCS_DIR = srcs

FILES = push_swap.c \
		price_checker_utils.c \
		stack_utils.c \
		stack_utils_2.c \
		node_utils.c \
		sort_utils.c \
		push_utils.c \
		swap_utils.c \
		rotate_utils.c \
		reverse_rotate_utils.c \
		tiny_sort_utils.c 
SRCS = $(addprefix $(SRCS_DIR)/,$(FILES))
OBJS = $(SRCS:.c=.o)

all: libft $(NAME)

libft:
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft

$(OBJS): | $(INCLUDES_DIR)

$(INCLUDES_DIR):
	mkdir -p $(INCLUDES_DIR)

$(SRCS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCLUDES_DIR)/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all
