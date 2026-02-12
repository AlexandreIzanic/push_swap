/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:48:36 by alex              #+#    #+#             */
/*   Updated: 2025/11/24 12:44:44 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
#include <stdio.h>
void	add(unsigned int nb, char *c)
{
	if (nb == 0)
		*c = *c - 32;
	*c = *c;
}

int	main(void)
{
	char str[] = "hello";

	printf("%s",str);
	ft_striteri(str, add);
	printf("%s",str);
	return (0);
}
*/
