/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:46:43 by alex              #+#    #+#             */
/*   Updated: 2025/11/24 12:22:34 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
#include <stdio.h>
void	add(void *content)
{
	char *str = (char *)content; 
	if (str && str[0] != '\0')
	str[0] = ft_toupper(str[0]); 
	}
*/

/*
#include <stdlib.h>
int	main(void)
{
	t_list	*head, *e, *f;
	
	head = malloc(sizeof(t_list));
	e = malloc(sizeof(t_list));
	f = malloc(sizeof(t_list));

	head->content = ft_strdup("test");
	e->content = ft_strdup("abc");
	f->content = ft_strdup("cde");

	head->next = e;
	e->next = f;
	f->next = 0;
	printf("%s\n", (char *)head->content);
	printf("%s\n", (char *)f->content);
	ft_lstiter(head, add);	
	printf("%s\n", (char *)head->content);
	printf("%s\n", (char *)f->content);
	return(0);
}
*/
