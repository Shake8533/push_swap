/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:21:02 by palefebv          #+#    #+#             */
/*   Updated: 2024/10/21 20:21:35 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
/*

#include <stdio.h>

int main() {
	const char *str = "Hello, World!";
	char *substring;

	// Test 1: Normal case
	substring = ft_substr(str, 7, 5);
	printf("Substring (start=7, len=5): %s\n", substring);
	free(substring);

	// Test 2: Starting index out of range
	substring = ft_substr(str, 15, 5);
	printf("Substring (start=15, len=5): %s\n", substring);
	free(substring);

	// Test 3: Length exceeds available length
	substring = ft_substr(str, 0, 20);
	printf("Substring (start=0, len=20): %s\n", substring);
	free(substring);

	// Test 4: Empty string input
	substring = ft_substr("", 0, 5);
	printf("Substring (empty string): %s\n", substring);
	free(substring);
	
	substring = ft_substr(str, 12, 5);
	printf("Substring (start=13, len=5): %s\n", substring);
	free(substring);

	return 0;
}*/
