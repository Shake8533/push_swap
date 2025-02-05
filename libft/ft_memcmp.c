/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:47:22 by palefebv          #+#    #+#             */
/*   Updated: 2024/10/15 20:52:46 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
/*
#include<stdio.h>
#include <string.h>

int main() {
    // Cas de test 1: Comparaison de deux chaînes identiques
    const char *str1 = "Hello, World!";
    const char *str2 = "Hello, World!";
    int result1 = ft_memcmp(str1, str2, strlen(str1));
    printf("Test 1: ft_memcmp(str1, str2) = %d (attendu: 0)\n", result1);

    // Cas de test 2: Comparaison de deux chaînes différentes
    const char *str3 = "Hello, World!";
    const char *str4 = "Hello, world!";
    int result2 = ft_memcmp(str3, str4, strlen(str3));
    printf("Test 2: ft_memcmp(str3, str4) = %d (attendu: non 0)\n", result2);

    // Cas de test 3: Comparaison de différentes longueurs
    const char *str5 = "abc";
    const char *str6 = "abcd";
    int result3 = ft_memcmp(str5, str6, 3);
    printf("Test 3: ft_memcmp(str5, str6) = %d (attendu: 0)\n", result3);

    // Cas de test 4: Comparaison d'une chaîne vide et d'une chaîne non vide
    const char *str7 = "";
    const char *str8 = "a";
    int result4 = ft_memcmp(str7, str8, 1);
    printf("Test 4: ft_memcmp(str7, str8) = %d (attendu: < 0)\n", result4);

    // Cas de test 5: Comparaison avec des caractères différents
    const char *str9 = "abcdef";
    const char *str10 = "abcxef";
    int result5 = ft_memcmp(str9, str10, 6);
    printf("Test 5: ft_memcmp(str9, str10) = %d (attendu: non 0)\n", result5);

    return 0;
}*/
