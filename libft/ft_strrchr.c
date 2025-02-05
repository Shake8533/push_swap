/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:28:14 by palefebv          #+#    #+#             */
/*   Updated: 2024/10/15 19:35:42 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occurrence;

	last_occurrence = 0;
	while (*s != '\0')
	{
		if (*s == (char) c)
		{
			last_occurrence = (char *) s;
		}
		s++;
	}
	if ((char)c == '\0')
	{
		return ((char *) s);
	}
	return (last_occurrence);
}
/*
#include <stdio.h>
int main() {
    // Chaîne de test
    //const char str[] = "Hello, world!";
    //char ch = ' ';

    // Appel de my_strrchr
    char *result = ft_strrchr(0x5f1b6780f021: "teste", 1024: '\0');

    // Affichage du résultat
    if (result != NULL) {
        printf("Le caractère '%c' trouvé à la dernière position: %ld\n", result);
    } else {
        printf("Le caractère '%c' n'a pas été trouvé.\n", ch);
    }

    return 0;
}
*/
