/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:23:53 by palefebv          #+#    #+#             */
/*   Updated: 2024/10/21 20:27:34 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_str;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	end = 0;
	while (s1[end])
		end++;
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	trimmed_str = (char *)malloc((end - start + 1) * sizeof(char));
	if (!trimmed_str)
		return (NULL);
	i = 0;
	while (start < end)
		trimmed_str[i++] = s1[start++];
	trimmed_str[i] = '\0';
	return (trimmed_str);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*s1 = "   Hello, World!   ";
	char	*set = " ";
	char	*trimmed;

	// Appel de ft_strtrim avec les chaînes s1 et set
	trimmed = ft_strtrim(s1, set);
	if (trimmed)
	{
		printf("Original: '%s'\n", s1);
		printf("Trimmed: '%s'\n", trimmed);
		free(trimmed);  // N'oublie pas de libérer la mémoire allouée !
	}
	else
	{
		printf("Erreur lors de l'allocation de mémoire.\n");
	}
	return (0);
}*/
