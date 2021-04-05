# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 08:37:30 by ttampio           #+#    #+#              #
#    Updated: 2021/04/03 15:33:25 by jrignell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FT_PRINTF = ft_printf/libftprintf.a
ODIR = obj
CFLAGS = -Wall -Wextra -Werror
CC = gcc
SRC =  \
		ft_abs.c \
		ft_arraydel.c \
    	ft_atoi.c \
		ft_bzero.c \
		ft_check_malloc.c \
    	ft_isalnum.c \
    	ft_isalpha.c \
    	ft_isascii.c \
    	ft_isdigit.c \
		ft_islower.c \
    	ft_isprint.c \
    	ft_isspace.c \
		ft_isupper.c \
		ft_itoa_base_u.c \
		ft_itoa_base.c \
    	ft_itoa.c \
		ft_joindel.c \
		ft_lftoa.c \
		ft_lstaddend.c \
		ft_lstnew.c \
    	ft_memalloc.c \
    	ft_memcpy.c \
    	ft_memdel.c \
		ft_putchar_fd.c \
    	ft_putendl_fd.c \
    	ft_putstr_fd.c \
		ft_strarrlen.c \
    	ft_strchr.c \
		ft_strcpy.c \
    	ft_strdel.c \
    	ft_strdup.c \
    	ft_strjoin.c \
		ft_strjoinfree.c \
    	ft_strlen.c \
		ft_strncpy.c \
    	ft_strnew.c \
    	ft_strsplit.c \
    	ft_strsub.c \
    	ft_tolower.c \
    	ft_toupper.c \
		get_next_line.c \

BTREEFILES =	

COMPAREFILES =	

QUEUEFILES =	

STACKFILES =	ft_isempty.c \
				ft_pop.c \
				

TRIEFILES =		

DLLFILES =		

OBJ =	$(patsubst %.c, $(ODIR)/src/%.o, $(SRC)) \
		$(patsubst %.c, $(ODIR)/compare/%.o, $(COMPAREFILES)) \
		$(patsubst %.c, $(ODIR)/stack/%.o, $(STACKFILES)) \
		$(patsubst %.c, $(ODIR)/queue/%.o, $(QUEUEFILES)) \
		$(patsubst %.c, $(ODIR)/btree/%.o, $(BTREEFILES)) \
		$(patsubst %.c, $(ODIR)/trie/%.o, $(TRIEFILES)) \
		$(patsubst %.c, $(ODIR)/doubly_linked_list/%.o, $(DLLFILES))

$(ODIR)/%.o: %.c | $(ODIR)
	@$(CC) -c -o $@ $< -I ft_printf/includes -I includes/ $(CFLAGS)

all: $(FT_PRINTF) $(NAME)

norm:
	@norminette ft_*.c libft.h

index:
	@ranlib $(NAME)

$(ODIR):
	@/bin/mkdir $(ODIR)
	@/bin/mkdir $(ODIR)/src
	@/bin/mkdir $(ODIR)/compare
	@/bin/mkdir $(ODIR)/stack
	@/bin/mkdir $(ODIR)/queue
	@/bin/mkdir $(ODIR)/btree
	@/bin/mkdir $(ODIR)/trie
	@/bin/mkdir $(ODIR)/doubly_linked_list

$(NAME): $(OBJ)
	@ar rc $@ $^
	@ar rc $@ ft_printf/obj/*.o

$(FT_PRINTF):
	@make -C ft_printf/ fclean && make -C ft_printf/

clean:
	@make -C ft_printf/ clean
	@/bin/rm -rf $(ODIR)

fclean: clean
	@make -C ft_printf/ fclean
	@/bin/rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
