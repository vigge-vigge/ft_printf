# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vakande <vakande@student.42barcelona.      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/18 12:50:51 by vakande           #+#    #+#              #
#    Updated: 2025/04/08 14:56:02 by vakande          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -Iinclude -Ilibft

SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft

NAME = libftprintf.a

SRCS = $(addprefix $(SRC_DIR)/, ft_printf.c ft_printf_utils.c ft_print_hex.c ft_print_ptr.c \
		ft_print_unsigned.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT = $(LIBFT_DIR)/libft.a

__dep_libft:
	make -C $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJS)
			make -C $(LIBFT_DIR)
			ar rcs $(NAME) $(OBJS) $(LIBFT)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
					mkdir -p $(OBJ_DIR)
					$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) $(OBJS)
				make -C $(LIBFT_DIR) clean

fclean: clean
				$(RM) $(NAME) printf_test
				make -C $(LIBFT_DIR) fclean

re:				fclean all

test: $(NAME)
		$(CC) $(CFLAGS) main.c $(NAME) $(LIBFT) -o printf_test

.PHONY:			all clean fclean re test
