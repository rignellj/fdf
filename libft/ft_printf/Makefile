# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/05 15:53:22 by jrignell          #+#    #+#              #
#    Updated: 2021/04/05 20:07:05 by jrignell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

CC = /usr/bin/gcc
MKDIR = /bin/mkdir
RM = /bin/rm
AR = /usr/bin/ar

INC_DIR = includes/

OBJ_DIR =	obj/
SRC_DIR =	srcs/

GREEN=\033[0;32m
WHITE=\033[1;37m
NC=\033[0m

SRCS = 	ft_printf.c \
		ft_dprintf.c \
		ft_parse_diouxf.c \
		ft_parse_hh_h_ll_l.c \
		check_bef_format.c \
		check_bef_format_u.c \
		ft_parse_width.c \
		ft_parse_f.c \
		ft_precision.c \
		ft_parse_csp_percent.c \
		ft_parse_flags.c \
		ft_helpers.c \
		ft_helpers_check_functions.c \
		ft_parse_brk.c \
		form_struct.c \
		print_array.c \
		ft_str_free.c \

OBJ = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

all: obj $(NAME)

obj:
	@$(MKDIR) -p $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@printf -- "${GREEN}creating object\t${WHITE}[ $@ ]${NC}\n"
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(AR) rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@$(RM) -f $(OBJ)

fclean: clean
	@$(RM) -f $(NAME)

re: fclean all
	
.PHONY: all clean fclean re
