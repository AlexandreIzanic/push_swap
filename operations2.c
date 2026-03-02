/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:00:00 by alex              #+#    #+#             */
/*   Updated: 2026/03/02 12:00:00 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	rotate(t_node **head)
{
	t_node	*first;
	t_node	*last;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	last = *head;
	while (last->next)
		last = last->next;
	*head = first->next;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	(*head)->prev = NULL;
}

void	ra(t_node **head_a)
{
	rotate(head_a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_node **head_b)
{
	rotate(head_b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_node **head_a, t_node **head_b)
{
	rotate(head_a);
	rotate(head_b);
	ft_putstr_fd("rr\n", 1);
}
