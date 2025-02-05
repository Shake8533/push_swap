/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:45:29 by palefebv          #+#    #+#             */
/*   Updated: 2024/10/15 13:13:47 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
/*

#include <stdio.h>
#include <string.h>
int main(void)
{
    char str[20];

    strcpy(str, "Hello, World!");
    printf("Avant bzero : '%s'\n", str);

    ft_bzero(str, 6);
    printf("Après bzero : '%s'\n", str + 6);

    return 0;
}*/
