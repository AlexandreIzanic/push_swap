/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:53:39 by alex              #+#    #+#             */
/*   Updated: 2025/11/24 12:24:28 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new;
	void	*content;

	if (!lst || !f)
		return (NULL);
	head = NULL;
	while (lst)
	{
		content = f(lst->content);
		new = ft_lstnew(content);
		if (!new)
		{
			del(content);
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, new);
		lst = lst->next;
	}
	return (head);
}
/*
static void	*map_f(void *content)
{
	char *str = (char *)content;
	char *new = ft_strdup(str);
	new[0] = new[0] + 1;
	return (new);
	}
	
	static void	del(void *content)
	{
		free(content);
		}*/
/*
#include <stdlib.h>
#include <stdio.h>
int	main(void)
{
	t_list	*head, *e, *f, *new;
	
	head = malloc(sizeof(t_list));
	e = malloc(sizeof(t_list));
	f = malloc(sizeof(t_list));
	new = malloc(sizeof(t_list));

	head->content = ft_strdup("1");
	e->content = ft_strdup("2"); 
	f->content = ft_strdup("3");

	head->next = e;
	e->next = f;
	f->next = 0;
	
	new = ft_lstmap(head, map_f, del); 
	printf("%s", (char *)new->content);
	printf("%s", (char *)new->next->content);
	return(0);
}
*/
