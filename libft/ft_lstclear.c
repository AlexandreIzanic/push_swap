/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:46:39 by alex              #+#    #+#             */
/*   Updated: 2025/11/24 12:42:56 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = 0;
}
/*
static void	del(void *content)
{
	free(content);
	}*/

/*
#include <stdlib.h>
#include <stdio.h>
int	main(void)
{
	t_list	*head, *e, *f;
	
	head = malloc(sizeof(t_list));	
	e = malloc(sizeof(t_list));	
	f = malloc(sizeof(t_list));	

	head->content = "1";
	e->content = "2";
	f->content = "3";

	head->next = e;
	e->next = f;
	f->next = 0;

	ft_lstclear(&e, del);
	
	return (0);
}
*/
