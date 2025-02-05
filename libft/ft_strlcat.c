/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:47:15 by palefebv          #+#    #+#             */
/*   Updated: 2024/10/15 18:52:27 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (size + src_len);
	i = 0;
	while (src[i] && (dst_len + i) < (size - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if ((dst_len + i) < size)
		dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
/*
#include <stdio.h>
int main() {
    char dst[20] = "Hello, ";  // Buffer de destination avec contenu initial
    const char src[] = "world!"; // Chaîne source à ajouter

    // Appel de strlcat
    unsigned int result = ft_strlcat(dst, src, sizeof(dst));

    // Affichage des résultats
    printf("Chaîne concaténée: %s\n", dst);
    printf("Longueur totale théorique (sans troncation): %u\n", result);

    return 0;
}
*/
