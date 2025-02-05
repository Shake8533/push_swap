/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:08:16 by palefebv          #+#    #+#             */
/*   Updated: 2024/07/08 19:15:14 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int main() {
    // Chaînes de test
    const char str1[] = "Hello, world!";
    const char str2[] = "Hello, there!";

    // Comparaison des chaînes sur les 7 premiers caractères
    int result = ft_strncmp(str1, str2, 9);

    // Affichage du résultat
    if (result < 0) {
        printf("'%s' est inférieur à '%s' 
        (sur les 7 premiers caractères)\n", str1, str2);
    } else if (result > 0) {
        printf("'%s' est supérieur à '%s' 
        (sur les 7 premiers caractères)\n", str1, str2);
    } else {
        printf("Les 7 premiers caractères 
        de '%s' et '%s' sont égaux\n", str1, str2);
    }

    return 0;
}*/
