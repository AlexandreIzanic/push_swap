/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:00:00 by alex              #+#    #+#             */
/*   Updated: 2026/03/02 12:00:00 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	swap(t_node **head)
{
	t_node	*first;
	t_node	*second;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*head = second;
}

void	sa(t_node **head_a)
{
	swap(head_a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_node **head_b)
{
	swap(head_b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_node **head_a, t_node **head_b)
{
	swap(head_a);
	swap(head_b);
	ft_putstr_fd("ss\n", 1);
}

static void	push(t_node **src, t_node **dst)
{
	t_node	*first;

	if (!src || !*src || !dst)
		return ;
	first = *src;
	*src = first->next;
	if (*src)
		(*src)->prev = NULL;
	first->next = *dst;
	if (*dst)
		(*dst)->prev = first;
	first->prev = NULL;
	*dst = first;
}

void	pa(t_node **head_a, t_node **head_b)
{
	push(head_b, head_a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_node **head_a, t_node **head_b)
{
	push(head_a, head_b);
	ft_putstr_fd("pb\n", 1);
}
