/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:48:29 by alex              #+#    #+#             */
/*   Updated: 2025/11/24 12:44:22 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	word_count(const char *s, char c)
{
	int	i;
	int	n;
	int	in_word;

	n = 0;
	i = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] != c && !in_word)
		{
			in_word = 1;
			n++;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (n);
}

static void	*ft_free(char **tab, int n)
{
	if (!tab)
		return (0);
	while (n > 0)
	{
		n--;
		free(tab[n]);
	}
	free(tab);
	return (0);
}

static char	*allocate_word(char **tab, int word, const char *s, int j)
{
	int	i;

	tab[word] = malloc(j + 1);
	if (!tab[word])
		return (ft_free(tab, word));
	i = 0;
	while (i < j)
	{
		tab[word][i] = s[i - j];
		i++;
	}
	tab[word][i] = '\0';
	return (tab[word]);
}

static char	**process_words(char **tab, const char *s, char c)
{
	int	j;
	int	word;

	word = 0;
	j = 0;
	while (*s)
	{
		if (*s != c)
			j++;
		else if (*s == c && j > 0)
		{
			if (!allocate_word(tab, word, s, j))
				return (NULL);
			word++;
			j = 0;
		}
		s++;
	}
	if (j > 0 && !allocate_word(tab, word++, s, j))
		return (NULL);
	tab[word] = NULL;
	return (tab);
}

char	**ft_split(const char *s, char c)
{
	char	**tab;

	tab = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!tab)
		return (NULL);
	return (process_words(tab, s, c));
}
/*
#include <stdio.h>
int 	main(int argc, char *argv[])
{
	char	**tab;
	char	*str;
	char	c;
	int	word;
	int	j;
	
	j = 0;
	word = 0;
	str = argv[1] ? argv[1] : "Hello world";
	c = argv[2] ? argv[2][0] : 'o';

	tab = ft_split(str, c);
	while(tab[word] != 0)
	{
		printf("%s\n", tab[word]);	
		word++;
	}	
	return(0);
}*/
