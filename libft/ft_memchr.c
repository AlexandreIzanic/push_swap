/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:47:00 by alex              #+#    #+#             */
/*   Updated: 2025/11/24 12:25:00 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *buff, int ch, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	uch;

	uch = (unsigned char)ch;
	str = (unsigned char *)buff;
	i = 0;
	while (i < n)
	{
		if (str[i] == uch)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
int	main(void)
{
	char s[] = {0, 1, 2 ,3 ,4 ,5};
	printf("test %p",ft_memchr(s, 0, 1));
	return (0);
}
*/
