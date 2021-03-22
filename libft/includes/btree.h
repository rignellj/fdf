/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 14:44:13 by jrignell          #+#    #+#             */
/*   Updated: 2021/02/05 14:20:24 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_H
# define BTREE_H

# include <unistd.h>
# include "libft.h"

# define LEFT_CHILD -1
# define RIGHT_CHILD 1

# define CBLACK "\x1B[30m"
# define CBLACKB "\x1B[1;30m"

# define CRED "\x1B[31m"
# define CREDB "\x1B[1;31m"

# define CRESET "\x1B[0m"
# define BGWHITE "\x1B[47m"

typedef struct			s_btree
{
	struct s_btree		*left;
	struct s_btree		*right;
	void				*item;
}						t_btree;

enum					e_rb_color
{
	RB_BLACK,
	RB_RED
};

typedef struct			s_rb_btree
{
	struct s_rb_btree	*parent;
	struct s_rb_btree	*left;
	struct s_rb_btree	*right;
	void				*item;
	enum e_rb_color		color;
}						t_rb_btree;

/*
********************************************************************************
** BINARY TREE FUNCTIONS                                                      **
********************************************************************************
*/

t_btree					*btree_create_node(void *item);

void					btree_insert_data(t_btree **root, void *item,
						int (*cmpf)(void *, void *));

/*
********************************************************************************
** BINARY TREE / RED BLACK TREE FUNCTIONS                                     **
********************************************************************************
*/

int						btree_level_count(t_btree *root);

void					btree_apply_preorder(t_btree *root,
						void (*applyf)(void *));
void					btree_apply_inorder(t_btree *root,
						void (*applyf)(void *));
void					btree_apply_postorder(t_btree *root,
						void (*applyf)(void *));

void					*btree_search_item(t_btree *root, void *data_ref,
						int (*cmpf)(void *, void *));

/*
********************************************************************************
** RED BLACK TREE FUNCTIONS                                                   **
********************************************************************************
*/

int						rb_which_child(t_rb_btree *root,
						int (*cmpf)(void *, void *));

t_rb_btree				*rb_create_node(void const *item, size_t content_size);

void					rb_insert(t_rb_btree **root, void *data,
						int (*cmpf)(void *, void *));
void					rb_check_color(t_rb_btree **root, t_rb_btree *node,
						int (*cmpf)(void *, void *));
void					rb_correct_tree(t_rb_btree **root_node,
						t_rb_btree *root, int (*cmpf)(void *, void *));
void					rb_rotate(t_rb_btree **root_node, t_rb_btree *root,
						int (*cmpf)(void *, void *));
void					rb_rotate_left(t_rb_btree **root, t_rb_btree *node,
						int (*cmpf)(void *, void *));
void					rb_rotate_right(t_rb_btree **root, t_rb_btree *node,
						int (*cmpf)(void *, void *));
void					rb_double_rotation_right(t_rb_btree **root,
						t_rb_btree *node, int (*cmpf)(void *, void *));
void					rb_double_rotation_left(t_rb_btree **root,
						t_rb_btree *node, int (*cmpf)(void *, void *));
void					rb_print_inorder(t_rb_btree *node,
						void (*print)(void *, int));
void					rb_print_by_level(t_rb_btree *node, t_list *list,
						void (*print)(void *, int));
void					rb_print_current(void *item, int color);

#endif
