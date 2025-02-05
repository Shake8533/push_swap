/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:41:46 by palefebv          #+#    #+#             */
/*   Updated: 2024/10/21 20:43:02 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_str;

	if (!s || !f)
		return (NULL);
	new_str = (char *)malloc((sizeof(char) * (ft_strlen(s) + 1)));
	if (!new_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
/*
#include <stdio.h>

char	ft_toupper_index(unsigned int i, char c)
{
	(void)i; // On ne se sert pas de l'index ici
	if (c >= 'a' && c <= 'z')
		return (c - 32); // Convertir en majuscule
	return (c);
}

int	main(void)
{
	char *str = "hello world!";
	char *result;

	result = ft_strmapi(str, ft_toupper_index);
	if (result)
	{
		printf("Original: %s\n", str);
		printf("Modifié: %s\n", result);
		free(result);
	}
	else
	{
		printf("Erreur de mémoire\n");
	}
	return (0);
}*/
