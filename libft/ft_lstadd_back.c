/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:46:36 by alex              #+#    #+#             */
/*   Updated: 2025/11/24 12:21:36 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	curr = *lst;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	t_list	*head, *e, *f, *g, *new;
	head = malloc(sizeof(t_list));
	e = malloc(sizeof(t_list));
	f = malloc(sizeof(t_list));
	g = malloc(sizeof(t_list));
	new = malloc(sizeof(t_list));

	head->content = "1";
	e->content = "2";
	f->content = "3";
	g->content = "4";
	new->content = "5";
	
	head->next = e;
	e->next = f;
	f->next = g;
	g->next = 0;

	ft_lstadd_back(&head, new);	
	printf("last next %s\n", (char *)g->next->content);
	return(0);
}
*/
