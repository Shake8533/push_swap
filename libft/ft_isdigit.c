/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdigit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:05:24 by palefebv          #+#    #+#             */
/*   Updated: 2024/10/14 14:10:30 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
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
	char testChar = 'd';
	if (ft_isdigit(testChar))
	{
		printf("%c est un chiffre.\n", testChar);
	}
	else
	{
		printf("%c n'est pas un chiffre.\n", testChar);
	}
	return 0;
}*/
