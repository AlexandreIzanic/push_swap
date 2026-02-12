/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:46:37 by alex              #+#    #+#             */
/*   Updated: 2025/11/24 12:21:45 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **t_lst, t_list *new)
{
	new->next = *t_lst;
	*t_lst = new;
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_list	*e;
	e = malloc(sizeof(t_list));
	e->content = "test";
	
	t_list *l;
	l = malloc(sizeof(t_list));
	l->content = "abc";

	ft_lstadd_front(&e, l);
	printf("%s\n", (char *)e->content);
	printf("%s\n", (char *)e->next->content);
	return (0);
}*/
