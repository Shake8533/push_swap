/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tolower.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:07:39 by palefebv          #+#    #+#             */
/*   Updated: 2024/10/15 19:10:46 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + ('a' - 'A'));
	}
	return (c);
}
/*
#include <stdio.h>
int main() {
    // Test de la fonction my_tolower
    char str[] = "HELLO, World!";
    
    printf("Original: %s\n", str);
    
    // Conversion de chaque caractère avec my_tolower
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = ft_tolower(str[i]);
    }

    printf("En minuscule: %s\n", str);

    return 0;
}
*/
