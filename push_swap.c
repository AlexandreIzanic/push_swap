/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:00:00 by alex              #+#    #+#             */
/*   Updated: 2026/03/02 12:00:00 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	get_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while ((1 << max_bits) < size)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_node **stack_a, t_node **stack_b)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	size = dlstsize(*stack_a);
	max_bits = get_max_bits(size);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*stack_a)->index >> i) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (1);
	if (argc == 2)
		size = parse_args(&stack_a, argv[1]);
	else
		size = parse_argv(&stack_a, argc, argv);
	if (size <= 0 || has_duplicate(stack_a))
	{
		ft_putstr_fd("Error\n", 2);
		dlstclear(&stack_a);
		return (1);
	}
	index_stack(stack_a);
	if (!is_sort(stack_a))
	{
		if (size == 2)
			sort_two(&stack_a);
		else if (size == 3)
			sort_three(&stack_a);
		else if (size <= 5)
			sort_five(&stack_a, &stack_b, size);
		else
			radix_sort(&stack_a, &stack_b);
	}
	dlstclear(&stack_a);
	dlstclear(&stack_b);
	return (0);
}
