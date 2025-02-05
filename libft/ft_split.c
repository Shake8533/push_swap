/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:28:07 by palefebv          #+#    #+#             */
/*   Updated: 2024/10/21 20:37:01 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*malloc_word(char const *s, char c)
{
	size_t	len;
	char	*word;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	len = 0;
	while (s[len] && s[len] != c)
	{
		word[len] = s[len];
		len++;
	}
	word[len] = '\0';
	return (word);
}

static void	free_words(char **words, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	size_t	i;

	if (!s)
		return (NULL);
	words = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			words[i] = malloc_word(s, c);
			if (!words[i])
				return (free_words(words, i), NULL);
			i++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	words[i] = NULL;
	return (words);
}
/*
#include <stdio.h>
int	main(void)
{
	char	**result;
	char	str[] = "Bonjour   tout le monde  ";
	char	sep = ' ';
	int		i;

	// Appel de la fonction ft_split
	result = ft_split(str, sep);
	if (!result)
	{
		printf("Erreur lors du split.\n");
		return (1);
	}

	// Affichage du résultat
	i = 0;
	while (result[i])
	{
		printf("Mot %d : %s\n", i + 1, result[i]);
		i++;
	}

	// Libération de la mémoire
	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);

	return (0);
}*/
