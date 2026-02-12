/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:46:48 by alex              #+#    #+#             */
/*   Updated: 2025/11/24 12:22:41 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_list	*head = malloc(sizeof (t_list));
	t_list	*e= malloc(sizeof (t_list));
	t_list	*f= malloc(sizeof (t_list));
	t_list	*g= malloc(sizeof (t_list));
	
	head->content = "1";
	e->content = "2";
	f->content = "3";
	g->content = "4";

	head->next = e;
	e->next = f;
	f->next = g;
	g->next = 0;

	t_list	*last;
	last = ft_lstlast(head);
	printf("%s", (char *)last->content);

	return(0);
}
*/
