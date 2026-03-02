/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                        +#+#+#+#+#+   +#+    */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define RESET "\033[0m"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

/* doubly linked list functions */
t_node	*dlstnew(int value);
void	dlstadd_back(t_node **lst, t_node *new_node);
void	dlstadd_front(t_node **lst, t_node *new_node);
t_node	*dlstlast(t_node *lst);
int		dlstsize(t_node *lst);
void	dlstiter(t_node *lst, void (*f)(int));
void	dlstiter_index(t_node *lst, void (*f)(int));
void	dlstclear(t_node **lst);

/* utils */
void	print_node(int value);
int	is_number(char *str);
int	is_sort(t_node *head);


// operations
void	swap(t_node **head);
void	sa(t_node **head_a);
void	sb(t_node **head_b);
void	ss(t_node **head_a, t_node **head_b);
void	rotate(t_node **head);
void	ra(t_node **head_a);
void	rb(t_node **head_b);
void	rr(t_node **head_a, t_node **head_b);
void	reverse_rotate(t_node **head);
void	rra(t_node **head_a);
void	rrb(t_node **head_b);
void	rrr(t_node **head_a, t_node **head_b);
void	push(t_node **src, t_node **dst);
void	pa(t_node **head_a, t_node **head_b);
void	pb(t_node **head_a, t_node **head_b);


#endif
