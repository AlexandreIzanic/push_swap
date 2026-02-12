/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:29:22 by alex              #+#    #+#             */
/*   Updated: 2025/11/23 15:06:45 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*e;

	e = malloc(sizeof(t_list));
	if (!e)
		return (0);
	e->content = content;
	e->next = 0;
	return (e);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list *e;

	e = ft_lstnew("abc");	
	printf("%s", (char *)e->content);
	return (0);
}*/
