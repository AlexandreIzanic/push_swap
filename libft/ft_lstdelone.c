/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:46:41 by alex              #+#    #+#             */
/*   Updated: 2025/11/24 12:22:03 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}

/*
static void	del(void *content)
{
	//	free(content);
	}
*/

/*
#include <stdio.h>
int	main(void)
{
	t_list *head, *e, *f;

	head = malloc(sizeof(t_list));	
	e= malloc(sizeof(t_list));	
	f= malloc(sizeof(t_list));	

	head->content = "1";
	e->content = "2";
	f->content = "3";

	head->next = e;
	e->next = f;
	f->next = 0;
		
	ft_lstdelone(f, del);
	printf("%s",(char *)e->next->content);
	
	return (0);
}
*/
