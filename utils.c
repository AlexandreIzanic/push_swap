/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:00:00 by alex              #+#    #+#             */
/*   Updated: 2026/03/02 12:00:00 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	check_digits(char *str, int i, int sign)
{
	long	nb;

	nb = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		nb = nb * 10 + (str[i] - '0');
		if (sign == 1 && nb > 2147483647)
			return (0);
		if (sign == -1 && nb > 2147483648L)
			return (0);
		i++;
	}
	return (1);
}

int	is_number(char *str)
{
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	if (!str || !*str)
		return (0);
	if (str[0] == '+' || str[0] == '-')
	{
		if (str[0] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (0);
	return (check_digits(str, i, sign));
}

int	is_sort(t_node *head)
{
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

void	index_stack(t_node *stack)
{
	t_node	*curr;
	t_node	*comp;
	int		index;

	curr = stack;
	while (curr)
	{
		index = 0;
		comp = stack;
		while (comp)
		{
			if (comp->value < curr->value)
				index++;
			comp = comp->next;
		}
		curr->index = index;
		curr = curr->next;
	}
}
