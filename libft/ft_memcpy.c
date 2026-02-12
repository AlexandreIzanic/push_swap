/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:43:18 by aizanic           #+#    #+#             */
/*   Updated: 2025/11/24 12:43:29 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t size)
{
	unsigned char	*p_dst;
	unsigned char	*p_src;

	if (!dst && !src)
		return (0);
	p_dst = (unsigned char *)dst;
	p_src = (unsigned char *)src;
	while (size > 0)
	{
		(*p_dst++) = (*p_src++);
		size--;
	}
	return (dst);
}

/*
#include <stdio.h>
int	main(void)
{
	int	array [] = { 54, 85, 20, 63, 21 };
	int * copy = NULL;
	int length = sizeof(int) * 5;

	copy = (int *)malloc(length);
	memcpy( copy, array, length);
	ft_memcpy(copy, array, length);
	
    	for( length=0; length<5; length++ )
	{		
		printf( "%d ", copy[ length ] );
    	}
	printf( "\n" );
	free( copy );
	return (0);
}
*/
