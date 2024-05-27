# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malee <malee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 23:01:22 by malee             #+#    #+#              #
#    Updated: 2024/05/28 04:01:21 by malee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# Compiler and Compiler flags
CC = cc
CFLAGS = -Os -Wall -Wextra -Werror -g

# C files
CFILES = push_swap.c \
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
SRC_DIR = srcs
SRCS = $(addprefix $(SRC_DIR)/,$(CFILES))

# Helper file directory
INCLUDE_DIR = includes

# Libraries
LIBRARIES = Libft
LIBS_DIR = Libs
LIBS = $(addprefix $(LIBS_DIR)/,$(LIBRARIES))
LIBFLAGS = -lft

# Objects
OBJ_DIR = ./obj
OBJS = $(addprefix $(OBJ_DIR)/, $(CFILES:%.c=%.o))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@for dir in $(LIBS); do \
        echo "Making $$dir"; \
        cd $$dir && $(MAKE); \
		cd -; \
    done
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(addprefix -L,$(LIBS)) $(LIBFLAGS)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	@for dir in $(LIBS); do \
        echo "Cleaning $$dir"; \
        cd $$dir && $(MAKE) clean; \
		cd -; \
    done
	@$(RM) -rf $(OBJ_DIR)

fclean: clean
	@for dir in $(LIBS); do \
        echo "Full Cleaning $$dir"; \
        cd $$dir && $(MAKE) fclean; \
		cd -; \
    done
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
