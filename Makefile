# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/22 11:22:17 by jrignell          #+#    #+#              #
#    Updated: 2021/03/22 14:55:41 by jrignell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CFLAGS = -Wall -Wextra -Werror

CC = /usr/bin/gcc
MAKE = /usr/bin/make
RM = /bin/rm
MKDIR = /bin/mkdir

LIBFT_DIR = ./libft/
MINLBX_DIR = ./minilibx/
SRC_DIR = ./src/
INC_DIR = ./includes/
OBJ_DIR = ./obj/
INCLUDES = 	-I $(MINLBX_DIR) -I $(LIBFT_DIR)includes \
			-I $(LIBFT_DIR)ft_printf/includes -I $(INC_DIR)

SRC_FILES =	main.c
OBJ_FILES = $(SRC_FILES:.c=.o)

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)
MINLBX = $(addprefix $(MINLBX_DIR), libmlx.a)

LINKS =	-L $(LIBFT_DIR) -lft -L $(MINLBX_DIR) \
		-Ofast -lmlx -framework OpenGL -framework AppKit

all: obj $(LIBFT) $(MINLBX) $(NAME)

obj:
	@$(MKDIR) -p $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
$(MINLBX):
	@$(MAKE) -C $(MINLBX_DIR)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(LINKS) -lm -o $(NAME)

clean:
	@$(RM) -Rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MINLBX_DIR) clean
	@echo "Objects removed!"

fclean: clean
	@$(RM) -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(NAME) removed!"

re: fclean all

fd: all ./includes/* ./libft/includes/libft.h
	@./$(NAME)

.PHONY: all clean fclean re
