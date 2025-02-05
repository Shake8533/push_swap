/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:23:54 by palefebv          #+#    #+#             */
/*   Updated: 2024/10/15 20:29:38 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int main() {
    // Cas de test 1: Recherche d'un caractère présent
    const char *str1 = "Hello, World!";
    char c1 = 'W';
    void *result1 = ft_memchr(str1, c1, strlen(str1));
    if (result1) {
        printf("Test 1: Trouvé '%c' à l'adresse: %p\n", c1, result1);
    } else {
        printf("Test 1: '%c' non trouvé.\n", c1);
    }

    // Cas de test 2: Recherche d'un caractère non présent
    char c2 = 'x';
    void *result2 = ft_memchr(str1, c2, strlen(str1));
    if (result2) {
        printf("Test 2: Trouvé '%c' à l'adresse: %p\n", c2, result2);
    } else {
        printf("Test 2: '%c' non trouvé.\n", c2);
    }

    // Cas de test 3: Recherche sur une chaîne vide
    const char *str2 = "";
    char c3 = 'a';
    void *result3 = ft_memchr(str2, c3, strlen(str2));
    if (result3) {
        printf("Test 3: Trouvé '%c' à l'adresse: %p\n", c3, result3);
    } else {
        printf("Test 3: '%c' non trouvé dans une chaîne vide.\n", c3);
    }

    // Cas de test 4: Recherche à la fin de la chaîne
    const char *str3 = "abcde";
    char c4 = 'e';
    void *result4 = ft_memchr(str3, c4, strlen(str3));
    if (result4) {
        printf("Test 4: Trouvé '%c' à l'adresse: %p\n", c4, result4);
    } else {
        printf("Test 4: '%c' non trouvé.\n", c4);
    }

    return 0;
}*/
