# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malee <malee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/06 20:12:49 by malee             #+#    #+#              #
#    Updated: 2024/05/28 04:02:52 by malee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# Compiler and Compiler flags
CC = cc
CFLAGS = -Os -Wall -Wextra -Werror -g

# C files
CFILES = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
       ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
       ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
       ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
       ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c \
       ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
       ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
       ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
       ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
       ft_lstiter.c ft_lstmap.c \
       ft_printf.c ft_printf_char_utils.c ft_printf_integer_utils.c \
       get_next_line.c get_next_line_utils.c
SRC_DIR = srcs
SRCS = $(addprefix $(SRC_DIR)/,$(CFILES))

# Helper file directory
INCLUDE_DIR = includes

# Objects
OBJ_DIR = ./obj
OBJS = $(addprefix $(OBJ_DIR)/, $(CFILES:%.c=%.o))

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) -I$(INCLUDE_DIR) -c $< -o $@

$(NAME): $(OBJS)
	@ar rf $@ $^

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) -rf $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
