/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:17:36 by palefebv          #+#    #+#             */
/*   Updated: 2024/10/15 19:22:59 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
/*
#include <stdio.h>

int main() {
    // Chaîne de test
    const char str[] = "Hello, world!";
    char ch = 'w';

    // Appel de ft_strchr
    char *result = ft_strchr(str, ch);

    // Affichage du résultat
    if (result != NULL) {
        printf("Le caractère '%c' trouvé à 
        la position: %ld\n", ch, result - str);
    } else {
        printf("Le caractère '%c' n'a pas été trouvé.\n", ch);
    }

    return 0;
}*/
