/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:46:34 by alex              #+#    #+#             */
/*   Updated: 2025/11/24 12:41:52 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	intlen(int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		i++;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nb)
{
	char		*str;
	int			i;
	long long	n;

	n = nb;
	i = intlen(nb) - 1;
	str = malloc(intlen(nb) * sizeof(char) + 1);
	if (!str)
		return (0);
	str[intlen(nb)] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		str[i] = '0' + (n % 10);
		n = n / 10;
		i--;
	}
	return (str);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%s\n", ft_itoa(-542));
	return (0);
	}
*/	
