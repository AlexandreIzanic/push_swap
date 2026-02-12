/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:12:56 by aizanic           #+#    #+#             */
/*   Updated: 2025/11/24 12:43:38 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t size)
{
	unsigned char		*p_dst;
	const unsigned char	*p_src;

	p_src = (unsigned char *)src;
	p_dst = (unsigned char *)dst;
	if (!dst && !src)
		return (NULL);
	if (p_dst < p_src || p_dst >= p_src + size)
	{
		while (size--)
			*p_dst++ = *p_src++;
	}
	else
	{
		p_dst += size;
		p_src += size;
		while (size--)
			*(--p_dst) = *(--p_src);
	}
	return (dst);
}

// TODO TESTER AVEC 0 et mettre une regle
/*
#include <stdio.h>
int	main(void)
{
	int	array [] = { 54, 85, 20, 63, 21 };
	int * copy = NULL;
	int length = sizeof(int) * 5;

	copy = (int *)malloc(length);
//	memcpy( copy, array, length);
	ft_memmove(copy, array, length);
	
    	for( length=0; length<5; length++ )
	{		
		printf( "%d ", copy[ length ] );
    	}
	printf( "\n" );
	free( copy );
	return (0);
}
*/
