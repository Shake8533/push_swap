/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isascii.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:22:37 by palefebv          #+#    #+#             */
/*   Updated: 2024/10/14 14:37:56 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
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
	int testChar = 171;
	if (ft_isascii(testChar))
	{
		printf("%c est un caractere ascii\n", testChar);
	}
	else
	{
		printf("%c n'est pas un caractere ascii\n", testChar);
	}
	return 0;
}*/
