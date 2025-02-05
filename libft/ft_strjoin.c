/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:58:45 by palefebv          #+#    #+#             */
/*   Updated: 2024/07/18 13:13:21 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	if (s1)
		len1 = ft_strlen(s1);
	else
		len1 = 0;
	if (s2)
		len2 = ft_strlen(s2);
	else
		len2 = 0;
	new_str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!new_str)
		return (NULL);
	if (s1)
		ft_memcpy(new_str, s1, len1);
	if (s2)
		ft_memcpy(new_str + len1, s2, len2);
	new_str[len1 + len2] = '\0';
	return (new_str);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*result;
	char	*strs1[] = {"Hello", "world", "from", "42"};
	char	*sep1 = " ";
	char	*strs2[] = {"This", "is", "a", "test"};
	char	*sep2 = "-";
	char	*strs3[] = {"One", "more", "test"};
	char	*sep3 = "---";
	char	*strs4[] = {};
	char	*sep4 = ", ";
	int		size1 = 4;
	int		size2 = 4;
	int		size3 = 3;
	int		size4 = 0;

	// Test 1
	result = ft_strjoin(size1, strs1, sep1);
	if (result)
	{
		printf("Result 1: %s\n", result);
		free(result);
	}

	// Test 2
	result = ft_strjoin(size2, strs2, sep2);
	if (result)
	{
		printf("Result 2: %s\n", result);
		free(result);
	}

	// Test 3
	result = ft_strjoin(size3, strs3, sep3);
	if (result)
	{
		printf("Result 3: %s\n", result);
		free(result);
	}

	// Test 4 (size 0)
	result = ft_strjoin(size4, strs4, sep4);
	if (result)
	{
		printf("Result 4: %s\n", result);
		free(result);
	}
}*/
