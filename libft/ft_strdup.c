/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:02:28 by palefebv          #+#    #+#             */
/*   Updated: 2024/07/17 15:23:42 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;
	size_t	i;

	len = 0;
	while (s[len])
		len++;
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/*
#include <stdio.h>

int	main(void)
{
	char	src[100];
	char	*dup;

	printf("Entrez une chaine de caractere: ");
	fgets(src, 100, stdin);
	dup = ft_strdup(src);
	printf("Chaîne source: %s\n", src);
	printf("Chaîne dupliquée: %s\n", dup);
	free(dup);
}*/
