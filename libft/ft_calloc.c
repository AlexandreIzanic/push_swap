/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:21:55 by aizanic           #+#    #+#             */
/*   Updated: 2025/11/24 12:48:32 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t el_count, size_t el_size)
{
	size_t	total;
	void	*p;

	if (el_count != 0 && el_size != 0 && el_count > SIZE_MAX / el_size)
		return (NULL);
	total = el_count * el_size;
	p = malloc(total);
	if (!p)
		return (NULL);
	ft_memset(p, 0, total);
	return (p);
}
/*
#include <stdio.h>
int	main(void)
{
	int	*arr = ft_calloc(10, sizeof(int));
	int	i;
	i = 0;
	while(i < 10)
	{
		printf("%d\n", arr[i]);
		i++;
	}	
	
}*/
