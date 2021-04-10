# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/22 11:22:17 by jrignell          #+#    #+#              #
#    Updated: 2021/04/05 20:17:50 by jrignell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CFLAGS = -Wall -Wextra -Werror

CYAN=\033[1;36m
GREEN=\033[0;32m
YELLOW=\033[0;33m
WHITE=\033[1;37m
NC=\033[0m

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

SRC_FILES =	main.c \
			init.c \
			draw.c \
			rotate.c \
			key_press.c \
			expose_hook.c \
			mouse_press.c \
			perror_exit.c \
			print_usage.c \
			define_colors.c \
			read_from_file.c \
			write_into_screen.c \

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
	@printf -- "${GREEN}creating object\t${WHITE}[ $@ ]${NC}\n"
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(LIBFT):
	@printf "${CYAN}compiling libft..${NC}\n"
	@$(MAKE) -C $(LIBFT_DIR)
	@printf "${GREEN}libft compiled!\n${NC}"

$(MINLBX):
	@printf "${CYAN}compiling minilibx..${NC}\n"
	@$(MAKE) -C $(MINLBX_DIR) >/dev/null 2>&1
	@printf "${GREEN}minilibx compiled!\n${NC}"

$(NAME): $(OBJ)
	@printf "${CYAN}creating binary file ${WHITE}[${YELLOW} $@ ${WHITE}]${NC}\n"
	@$(CC) $(OBJ) $(LINKS) -lm -o $(NAME)
	@printf "${GREEN}done!\n${NC}"
	@printf "\n${WHITE}usage: ./fdf <input_file_to_read_from>\n${NC}"

clean:
	@printf "${CYAN}removing objects..${NC}"
	@$(RM) -Rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MINLBX_DIR) clean
	@printf " ${GREEN}done!\n${NC}"

fclean: clean
	@printf "${CYAN}removing executable..${NC}"
	@$(RM) -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@printf " ${GREEN}done!\n${NC}"

re: fclean all

fd: clean_obj obj $(NAME) ./includes/* ./libft/includes/libft.h
	@./fdf test_maps/42.fdf

clean_obj:
	@$(RM) -Rf $(OBJ_DIR)

.PHONY: all clean fclean re
