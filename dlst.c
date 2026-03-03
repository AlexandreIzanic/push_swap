/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:00:00 by alex              #+#    #+#             */
/*   Updated: 2026/03/02 12:00:00 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_node	*dlstnew(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_node	*dlstlast(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	dlstadd_back(t_node **lst, t_node *new_node)
{
	t_node	*last;

	if (!lst || !new_node)
		return (0);
	if (!*lst)
	{
		*lst = new_node;
		return (1);
	}
	last = dlstlast(*lst);
	last->next = new_node;
	new_node->prev = last;
	return (1);
}

int	dlstsize(t_node *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

void	dlstclear(t_node **lst)
{
	t_node	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}
