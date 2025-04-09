# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vakande <vakande@student.42barcelona.      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/18 12:50:51 by vakande           #+#    #+#              #
#    Updated: 2025/04/09 19:27:31 by vakande          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libftprintf.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -Iinclude -g
RM          = rm -f

SRC_DIR     = src
OBJ_DIR     = obj

SRCS        = $(addprefix $(SRC_DIR)/, ft_printf.c ft_printf_utils.c \
            ft_print_hex.c ft_print_ptr.c ft_print_unsigned.c utils.c)
OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Default target to compile the library
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Rule for compiling object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	$(RM) $(OBJS)

# Clean all files including the library and executables
fclean: clean
	$(RM) $(NAME) printf_test

# Rebuild everything from scratch
re: fclean all

# Test the library with main.c
test: $(NAME)
	$(CC) $(CFLAGS) main.c $(NAME) -o printf_test

# Explicitly mark these as phony targets
.PHONY: all clean fclean re test
