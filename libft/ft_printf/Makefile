# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/05 15:53:22 by jrignell          #+#    #+#              #
#    Updated: 2021/04/03 21:13:15 by jrignell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CC = gcc
INC_DIR = includes/
OBJ_DIR =	obj/
SRC_DIR =	srcs/

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
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

$(NAME): $(OBJ_DIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
	
.PHONY: all clean fclean re
