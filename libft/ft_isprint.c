/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isprint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:38:34 by palefebv          #+#    #+#             */
/*   Updated: 2024/10/14 14:52:12 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/*
#include<stdio.h>
int main()
{
	int testChar = 68;
	if (ft_isprint(testChar))
	{
		printf("Le caractère '%c' est imprimable.\n", testChar);
	}
	else
	{
		printf("Le caractère '%c' n'est pas imprimable.\n", testChar);
	}
	return 0;
}*/
