/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:32:56 by alex              #+#    #+#             */
/*   Updated: 2025/11/24 12:24:45 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		n;
	t_list	*current;

	if (!lst)
		return (0);
	current = lst;
	n = 0;
	while (current)
	{
		n++;
		current = current->next;
	}
	return (n);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_list *head = malloc(sizeof(t_list));
	t_list *f = malloc(sizeof(t_list));
	t_list *g = malloc(sizeof(t_list));
	t_list *h = malloc(sizeof(t_list));

	head->content = "1";
	f->content = "2";
	g->content = "3";
	h->content = "4";

	head->next = f;
	f->next = g;
	g->next = h;
	h->next = NULL;	
	
	printf("%d", ft_lstsize(head));
	
	return(0);
}*/
