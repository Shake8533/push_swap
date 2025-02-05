/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toupper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:56:29 by palefebv          #+#    #+#             */
/*   Updated: 2024/10/15 18:59:12 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - ('a' - 'A'));
	}
	return (c);
}
/*
#include <stdio.h>

int main() {
    // Test de la fonction my_toupper
    char str[] = "Hello, World!";
    
    printf("Original: %s\n", str);
    
    // Conversion de chaque caractère avec my_toupper
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = ft_toupper(str[i]);
    }

    printf("En majuscule: %s\n", str);

    return 0;
}*/
