# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/14 11:41:06 by ttampio           #+#    #+#              #
#    Updated: 2020/12/16 13:50:28 by jrignell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC =		gcc
CFLAGS =	-Wextra -Wall -Werror
ODIR =		obj
SRCDIR =	srcs
IDIR = 		includes
SRC =		$(patsubst %.c, core/%.c, $(SRC_CORE)) \
			$(patsubst %.c, util/%.c, $(SRC_UTIL))

SRC_CORE =	ft_printf.c ft_c_conv.c ft_s_conv.c ft_map_modifiers.c \
			ft_convert_to_str.c ft_p_conv.c ft_di_conv.c ft_o_conv.c \
			ft_u_conv.c ft_x_conv.c ft_upr_x_conv.c ft_f_conv.c \
			ft_percent_conv.c

SRC_UTIL =	ft_mask_decimal_trail.c

OBJ = $(addprefix $(ODIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(ODIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)

$(ODIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(IDIR)/ -I ../src/

$(ODIR):
	@/bin/mkdir $@
	@/bin/mkdir $@/core
	@/bin/mkdir $@/util

clean:
	@/bin/rm -rf $(ODIR)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
