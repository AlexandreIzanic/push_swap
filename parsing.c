/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:00:00 by alex              #+#    #+#             */
/*   Updated: 2026/03/02 12:00:00 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	has_duplicate(t_node *stack_a)
{
	t_node	*curr;
	t_node	*comp;

	curr = stack_a;
	while (curr)
	{
		comp = curr->next;
		while (comp)
		{
			if (curr->value == comp->value)
				return (1);
			comp = comp->next;
		}
		curr = curr->next;
	}
	return (0);
}

static void	free_split(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

static int	add_arg(t_node **stack_a, char *arg)
{
	if (!is_number(arg))
		return (0);
	if (!dlstadd_back(stack_a, dlstnew(ft_atoi(arg))))
		return (0);
	return (1);
}

int	parse_args(t_node **stack_a, char *str)
{
	char	**args;
	int		i;
	int		count;

	args = ft_split(str, ' ');
	if (!args)
		return (0);
	i = 0;
	count = 0;
	while (args[i])
	{
		if (!add_arg(stack_a, args[i++]))
		{
			free_split(args);
			return (-1);
		}
		count++;
	}
	free_split(args);
	return (count);
}

int	parse_argv(t_node **stack_a, int argc, char *argv[])
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			return (-1);
		if (!dlstadd_back(stack_a, dlstnew(ft_atoi(argv[i]))))
			return (-1);
		count++;
		i++;
	}
	return (count);
}
