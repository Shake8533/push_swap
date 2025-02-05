/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:49:40 by palefebv          #+#    #+#             */
/*   Updated: 2024/10/15 21:50:16 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] && big[i + j] && i + j < len
			&& big[i + j] == little[j])
			j++;
		if (!little[j])
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int    main(void)
{
    const char    *big = "Hello, World!";
    const char    *small = "World";
    const char    *not_found = "42";
    char        *result;

    result = ft_strnstr(big, small, 13);
    if (result)
        printf("Sous-chaîne trouvée: %s\n", result);
    else
        printf("Sous-chaîne non trouvée\n");
    result = ft_strnstr(big, not_found, 13);
    if (result)
        printf("Sous-chaîne trouvée: %s\n", result);
    else
        printf("Sous-chaîne non trouvée\n");
    result = ft_strnstr(big, small, 5);
    if (result)
        printf("Sous-chaîne trouvée: %s\n", result);
    else
        printf("Sous-chaîne non trouvée\n");
    return (0);
}*/
