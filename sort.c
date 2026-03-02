/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:00:00 by alex              #+#    #+#             */
/*   Updated: 2026/03/02 12:00:00 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	sort_three(t_node **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a < b && b > c && a < c)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a);
}

static int	find_min_pos(t_node *stack)
{
	int		min;
	int		pos;
	int		i;
	t_node	*current;

	min = stack->value;
	pos = 0;
	i = 0;
	current = stack;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			pos = i;
		}
		current = current->next;
		i++;
	}
	return (pos);
}

static void	push_min_to_b(t_node **stack_a, t_node **stack_b, int size)
{
	int	pos;

	pos = find_min_pos(*stack_a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(stack_a);
	}
	else
	{
		while (pos++ < size)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}

void	sort_five(t_node **stack_a, t_node **stack_b, int size)
{
	int	to_push;

	to_push = size - 3;
	while (to_push > 0)
	{
		push_min_to_b(stack_a, stack_b, size);
		size--;
		to_push--;
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	sort_two(t_node **stack_a)
{
	t_node	*head;

	head = *stack_a;
	if (head->value > head->next->value)
		ra(stack_a);
}
