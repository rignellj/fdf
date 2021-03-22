# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttampio <ttampio@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 08:37:30 by ttampio           #+#    #+#              #
#    Updated: 2021/02/05 17:02:30 by ttampio          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FT_PRINTF = ft_printf/libftprintf.a
ODIR = obj
CFLAGS = -Wall -Wextra -Werror
CC = gcc
SRC =  \
		ft_bzero.c \
    	ft_putchar.c \
    	ft_iputchar.c \
    	ft_strlen.c \
    	ft_memset.c \
    	ft_memcpy.c \
    	ft_memccpy.c \
    	ft_memmove.c \
    	ft_memchr.c \
    	ft_memcmp.c \
    	ft_strdup.c \
    	ft_strcpy.c \
    	ft_strncpy.c \
    	ft_strcat.c \
    	ft_strncat.c \
    	ft_strlcat.c \
    	ft_strchr.c \
    	ft_strrchr.c \
    	ft_strstr.c \
    	ft_strnstr.c \
    	ft_strcmp.c \
    	ft_strncmp.c \
    	ft_atoi.c \
    	ft_isalpha.c \
    	ft_isdigit.c \
    	ft_isalnum.c \
    	ft_isascii.c \
    	ft_isprint.c \
    	ft_isspace.c \
    	ft_toupper.c \
    	ft_tolower.c \
    	ft_memalloc.c \
    	ft_memdel.c \
    	ft_strnew.c \
    	ft_strdel.c \
    	ft_strclr.c \
    	ft_striter.c \
    	ft_striteri.c \
    	ft_strmap.c \
    	ft_strmapi.c \
    	ft_putstr.c \
    	ft_strequ.c \
    	ft_strnequ.c \
    	ft_strsub.c \
    	ft_strjoin.c \
    	ft_strtrim.c \
    	ft_strsplit.c \
    	ft_itoa.c \
    	ft_putendl.c \
    	ft_putnbr.c \
    	ft_putchar_fd.c \
    	ft_putstr_fd.c \
    	ft_putendl_fd.c \
    	ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstaddend.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_islower.c \
		ft_isupper.c \
		ft_strndup.c \
		ft_swap_size_t.c \
		ft_swaparr.c \
		ft_strchri.c \
		get_next_line.c \
		ft_dec_to_base.c \
		ft_strrev.c \
		ft_lltoa.c \
		ft_power_of_ten.c \
		ft_atoll.c \
		ft_contains_chrs.c \
		ft_memfree.c \
		ft_ret_filename.c \
		ft_ret_filename2.c \
		ft_strarrlen.c \
		ft_putstre.c \
		ft_strskp.c \
		ft_strpush.c \
		ft_strarrfree.c \
		ft_jmpesc.c \
		ft_strarrtostr.c \
		ft_isdelim.c \
		ft_isquote.c \
		ft_malchr.c \
    	ft_strremnchr.c \
    	ft_strunshift.c \
    	ft_strcmp_ci.c \
    	ft_putstr_ltrl.c \
    	ft_putendl_ltrl.c \
    	ft_charcnt.c \
    	ft_charscnt.c \
		ft_strlstc.c \
		ft_strjoinfree.c \
		ft_strremchr.c \
		ft_str_in_arr.c \
		ft_strarrsort.c \
		ft_itoa_base.c \
		ft_ptpsub.c \
		ft_abs.c \
		ft_contains_chrs_n.c \
		ft_power.c \
		ft_array_push.c \
		ft_strjoinchar.c \
		ft_arraydel.c \
		ft_arraynew.c \
		ft_strchrescpd.c \
		ft_math_operation.c \
		ft_division.c \
		ft_multiply.c \
		ft_modulo.c \
		ft_addition.c \
		ft_substraction.c \
		ft_lessthan.c \
		ft_greaterthan.c \
		ft_lessthan_orequal.c \
		ft_greaterthan_orequal.c \
		ft_logequal.c \
		ft_logiequal.c \
		ft_math_or.c \
		ft_math_and.c \
		ft_lstnew_or_add.c \
		ft_itoa_base64.c \
		ft_atoi_base64.c \
		ft_belongs_to_base.c \
		ft_contains_only_chrs.c \
		ft_putnchar.c \
		ft_straddchr.c \
		ft_chrescpd.c \
		ft_strarrjoin.c \

BTREEFILES =	rb_rotate.c \
				rb_insert.c \
				rb_create_node.c \
				rb_rotate_left.c \
				rb_which_child.c \
				rb_check_color.c \
				rb_rotate_right.c \
				rb_correct_tree.c \
				rb_print_inorder.c \
				rb_print_current.c \
				rb_print_by_level.c \
				btree_create_node.c \
				btree_insert_data.c \
				btree_level_count.c \
				btree_search_item.c \
				btree_apply_inorder.c \
				btree_apply_preorder.c \
				btree_apply_postorder.c \
				rb_double_rotation_left.c \
				rb_double_rotation_right.c

COMPAREFILES =	ft_compare_low_high.c \
				compare_int_low_high.c

QUEUEFILES =	queue_new.c \
				queue_push.c

STACKFILES =	ft_isempty.c \
				ft_stacknew.c \
				ft_pop.c \
				ft_stacksize.c \
				ft_stackpush.c \
				ft_peek.c \
				ft_stackadd.c \

TRIEFILES =		ft_trieadd.c \
				ft_trienew.c \
				ft_triedel.c \
				ft_trieiter.c \
				ft_triematch.c \
				ft_triesearch.c \
				ft_init_visit.c \
				ft_trie_init_visit.c \
				ft_trieiter_function.c \
				ft_trie_haschild_tovisit.c

DLLFILES =		ft_dlstadd.c \
				ft_dlstappend.c \
				ft_dlstdel.c \
				ft_dlstdelone.c \
				ft_dlstget_first.c \
				ft_dlstget_last.c \
				ft_dlstiter.c \
				ft_dlstiterif.c \
				ft_dlstmap.c \
				ft_dlstnew.c \
				ft_dinsert_after.c \
				ft_dinsert_before.c \

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
	@ar rc $@ ft_printf/obj/*/*.o

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
