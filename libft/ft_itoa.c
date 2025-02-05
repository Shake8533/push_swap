/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:37:44 by palefebv          #+#    #+#             */
/*   Updated: 2024/10/21 20:40:32 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(int n)
{
	size_t	len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	long	num;

	num = n;
	len = get_len(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		str[--len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	int	test_values[] = {0, 123, -456, 2147483647, -2147483648};
	char	*str;
	int		i;

	for (i = 0; i < 5; i++)
	{
		str = ft_itoa(test_values[i]);
		if (str)
		{
			printf("ft_itoa(%d) = %s\n", test_values[i], str);
			free(str); // N'oubliez pas de libérer la mémoire allouée
		}
		else
		{
			printf("ft_itoa(%d) a échoué\n", test_values[i]);
		}
	}
	return (0);
}*/
