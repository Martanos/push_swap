# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malee <malee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 23:01:22 by malee             #+#    #+#              #
#    Updated: 2024/05/06 20:58:45 by malee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I$(LIBFT_DIR) -I$(INCLUDES_DIR) -I$(SRCS_DIR)
INCLUDES_DIR = includes
LIBFT_DIR = Libft
SRCS_DIR = srcs

FILES = push_swap.c stack_utils.c node_utils.c algorithim_utils.c move_utils.c
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
