/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:35:08 by palefebv          #+#    #+#             */
/*   Updated: 2024/10/15 18:46:10 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (size == 0)
		return (src_len);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

/*
#include <stdio.h>
int main() {
    //char src[] = "Hello, world!";
    char dest[50]; // Buffer de destination

    // Appel de strlcpy
    unsigned int result = ft_strlcpy(dest, "lorem ipsum dolor sit amet", 15);

    // Affichage du résultat avec les fonctions standard de la bibliothèque
    //printf("Source: %s\n", src);
    printf("Destination (tronquée à 9 caractères): %s\n", dest);
    printf("Longueur de la source: %u\n", result);

    return 0;
}*/
