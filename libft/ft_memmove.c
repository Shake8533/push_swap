/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:06:33 by palefebv          #+#    #+#             */
/*   Updated: 2024/10/15 14:19:58 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d > s)
	{
		while (n--)
			d[n] = s[n];
	}
	else
	{
		while (n--)
			*d++ = *s++;
	}
	return (dest);
}
/*

#include<stdio.h>
int main() {
    char buffer[] = "Bonjour, monde!";
    printf("Avant memmove: %s\n", buffer);

    // Exemple de copie sans chevauchement
    ft_memmove(buffer + 8, buffer, 7); // Copie "Bonjour" à partir de "monde"
    printf("Après memmove (sans chevauchement): %s\n", buffer);

    // Réinitialisation du buffer
    char buffer2[] = "Bonjour, monde!";
    printf("Avant memmove avec chevauchement: %s\n", buffer2);

    // Exemple de copie avec chevauchement
    ft_memmove(buffer2 + 5, buffer2, 7); // Copie "Bonjour" à partir de "monde"
    printf("Après memmove (avec chevauchement): %s\n", buffer2);

    return 0;
}*/
