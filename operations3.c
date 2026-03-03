/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:00:00 by alex              #+#    #+#             */
/*   Updated: 2026/03/02 12:00:00 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	reverse_rotate(t_node **head)
{
	t_node	*first;
	t_node	*last;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	last = *head;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	first->prev = last;
	last->prev = NULL;
	last->next = first;
	*head = last;
}

void	rra(t_node **head_a)
{
	reverse_rotate(head_a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_node **head_b)
{
	reverse_rotate(head_b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_node **head_a, t_node **head_b)
{
	reverse_rotate(head_a);
	reverse_rotate(head_b);
	ft_putstr_fd("rrr\n", 1);
}

void	pa(t_node **head_a, t_node **head_b)
{
	push(head_b, head_a);
	ft_putstr_fd("pa\n", 1);
}
