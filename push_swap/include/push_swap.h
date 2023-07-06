/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:48:59 by sanghupa          #+#    #+#             */
/*   Updated: 2023/07/06 17:49:24 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"

# include <stdio.h>
# include <ctype.h>

// Limit Loop: use addition to while condition
# define MAX_ITER	1024

// Prevent Heap mem leak: use addition to char or array
# define DATA_SIZE	3072

# define RATIO		0.14

typedef struct s_stack
{
	int				len;
	struct s_dlst	*head;
	struct s_dlst	*tail;
}				t_stack;

/// @struct t_dlst
/// @brief Doubly Linked List Node.
/// This structure represents a node of a doubly linked list.
/// It contains information about the content and index of the node,
/// as well as pointers to the previous and next nodes in the list.
typedef struct s_dlst
{
	int				content;
	int				index;
	struct s_dlst	*prev;
	struct s_dlst	*next;
}				t_dlst;

/* push_swap_dlst_create.c */

/// @brief Create a new node for a doubly linked list.
/// This function creates a new node for a doubly linked list 
/// and initializes its members.
/// @param content The content to be stored in the node.
/// @return A pointer to the newly created node (t_dlst*) on success, 
/// or NULL if memory allocation fails.
t_dlst	*ft_dlstnew(int content);

/// @brief Add a node to the front of a doubly linked list.
/// This function adds a new node to the front of a doubly linked list.
/// @param dlst A pointer to a pointer to the head of the doubly linked list.
/// @param new A pointer to the node to be added.
void	ft_dlstadd_front(t_dlst *dlst[], t_dlst *new);

/// @brief Add a node to the end of a doubly linked list.
/// This function adds a new node to the end of a doubly linked list.
/// @param dlst A pointer to a pointer to the head of the doubly linked list.
/// @param new A pointer to the node to be added.
void	ft_dlstadd_back(t_dlst *dlst[], t_dlst *new);

/* push_swap_dlst_read.c */

/// @brief Get a node with a specific content from a doubly linked list.
/// This function searches for a node 
/// with a specific content in a doubly linked list.
/// @param dlst A pointer to a pointer to the head of the doubly linked list.
/// @param content The content to search for.
/// @return A pointer to the found node (t_dlst*) if found, 
/// or NULL if not found or if the list is empty.
t_dlst	*ft_dlstget(t_dlst *dlst[], int content);

/* push_swap_dlst_update.c */

/// @brief Update the content of a node in a doubly linked list.
/// This function updates the content of a node 
/// with a new value in a doubly linked list.
/// @param dlst A pointer to a pointer to the head of the doubly linked list.
/// @param old The old content value to search for.
/// @param new The new content value to update with.
void	ft_dlstupdate(t_dlst *dlst[], int old, int new);

/* push_swap_dlst_delete.c */

/// @brief Delete a single node from a doubly linked list.
/// This function deletes a single node from a doubly linked list.
/// @param dlst A pointer to a pointer to the head of the doubly linked list.
/// @param elem A pointer to the node to be deleted.
void	ft_dlstdelone(t_dlst *dlst[], t_dlst *elem);

/// @brief Pop the top element from a stack (doubly linked list).
/// This function pops the top element from a stack (doubly linked list) 
/// and returns it.
/// @param stack A pointer to a pointer to the head of the stack.
/// @return A pointer to the popped element (top of the stack).
t_dlst	*ft_pop(t_dlst *stack[]);

/// @brief Clear a doubly linked list and free all nodes.
/// This function clears a doubly linked list by freeing all its nodes.
/// @param dlst dlst A pointer to a pointer to the head 
/// of the doubly linked list.
void	ft_dlstclear(t_dlst *dlst[]);

/* push_swap_dlst_util.c */

/// @brief Get the size of a doubly linked list.
/// This function calculates and returns the number of nodes 
/// in a doubly linked list.
/// @param dlst 
/// @return 
int		ft_dlstsize(t_dlst *dlst);

/// @brief Get the last node of a doubly linked list.
/// This function returns a pointer to the last node of a doubly linked list.
/// @param dlst A pointer to the head of the doubly linked list.
/// @return A pointer to the last node of the doubly linked list.
t_dlst	*ft_dlstlast(t_dlst *dlst);

/// @brief Print the contents of a doubly linked list
/// This function prints the contents of a doubly linked list.
/// @param dlst dlst A pointer to a pointer to the head 
/// of the doubly linked list.
void	ft_dlstprint(t_dlst *dlst[]);

/* push_swap_error.c */

int		ft_error(void);

int		ft_iserror(char *arg[], int len);

/* push_swap_util.c */

long	ft_atol(const char *str);

/* push_swap_val_input.c */

int		ft_str_isdigit(char *str);

int		ft_str_isinteger(char *str);

int		ft_str_isduplicate(char *arg[]);

/* push_swap_rules.c */

void	swap(t_dlst *stack[], int ab);
void	push(t_dlst *stack_from[], t_dlst *stack_to[], int ab, int *lens);
void	rotate(t_dlst *stack[], int ab);
void	rerotate(t_dlst *stack[], int ab);

/* push_swap_rules_double.c */

void	ss(t_dlst *stack_a[], t_dlst *stack_b[]);
void	rr(t_dlst *stack_a[], t_dlst *stack_b[]);
void	rrr(t_dlst *stack_a[], t_dlst *stack_b[]);

/* push_swap_sort_preprocess.c */
int		set_threshold(int len, double ratio);
void	distribute_stacks(
			t_dlst *stack_a[], t_dlst *stack_b[], int threshold, int *lens);
void	preprocess(t_dlst *stack_a[], t_dlst *stack_b[], int len, int *lens);

/* push_swap_sort_basic.c */
void	sort_two(t_dlst *dlst[], int ab);
void	sort_three(t_dlst *dlst[], int ab);
void	sort_four(t_dlst *stack_a[], t_dlst *stack_b[], int *lens);

/* push_swap_sort_small.c */
void	nextorder_3(t_dlst *stack_a[], t_dlst *stack_b[], int *lens);
void	nextorder_4(t_dlst *stack_a[], t_dlst *stack_b[], int *lens);
void	nextorder_5(t_dlst *stack_a[], t_dlst *stack_b[], int *lens);
int		find_nextorder(t_dlst *stack_a[], t_dlst *stack_b[], int *lens);

/* push_swap_sort_large.c */
/* push_swap_sort_util.c */

void	ft_presort(t_dlst *dlst[], int len, int i);

int		ft_isordered(t_dlst *dlst[]);

int		ft_issorted(t_dlst *dlst[], int len);

int		find_min(t_dlst *stack[]);

int		find_max(t_dlst *stack[]);

/* push_swap_sort.c */
int		is_nextorder(
			t_dlst *a_head, t_dlst *a_tail, t_dlst *b_head, t_dlst *b_tail);
int		sort_small(t_dlst *stack_a[], t_dlst *stack_b[], int len, int *lens);

/* push_swap.c */

#endif
