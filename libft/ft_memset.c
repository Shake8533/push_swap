/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:56:20 by palefebv          #+#    #+#             */
/*   Updated: 2024/10/14 15:48:52 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>
int main()
{
	char str[50] = "Bonjour, ceci est un test de ft_memset.";
	printf("Avant memset : %s\n", str);
	ft_memset(str, 'c', 7);

	printf("Après ft_memset : %s\n", str);
	return 0;
}*/
