/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:00:00 by alex              #+#    #+#             */
/*   Updated: 2026/03/02 12:00:00 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft/libft.h"
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

/* doubly linked list functions */
t_node	*dlstnew(int value);
int		dlstadd_back(t_node **lst, t_node *new_node);
t_node	*dlstlast(t_node *lst);
int		dlstsize(t_node *lst);
void	dlstclear(t_node **lst);

/* utils */
int		is_number(char *str);
int		is_sort(t_node *head);

/* parsing */
void	index_stack(t_node *stack);
int		has_duplicate(t_node *stack_a);
int		parse_args(t_node **stack_a, char *str);
int		parse_argv(t_node **stack_a, int argc, char *argv[]);

/* sorting */
void	sort_two(t_node **stack_a);
void	sort_three(t_node **stack_a);
void	sort_five(t_node **stack_a, t_node **stack_b, int size);
void	radix_sort(t_node **stack_a, t_node **stack_b);

/* operations */
void	push(t_node **src, t_node **dst);
void	sa(t_node **head_a);
void	sb(t_node **head_b);
void	ss(t_node **head_a, t_node **head_b);
void	ra(t_node **head_a);
void	rb(t_node **head_b);
void	rr(t_node **head_a, t_node **head_b);
void	rra(t_node **head_a);
void	rrb(t_node **head_b);
void	rrr(t_node **head_a, t_node **head_b);
void	pa(t_node **head_a, t_node **head_b);
void	pb(t_node **head_a, t_node **head_b);

#endif
