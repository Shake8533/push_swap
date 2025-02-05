/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:11:07 by palefebv          #+#    #+#             */
/*   Updated: 2024/10/14 14:21:50 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)
		|| (c >= 48 && c <= 57))
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
	char testChar = 'Z';
	if (ft_isalnum(testChar))
	{
		printf("%c est alpha-numérique.\n", testChar);
	}
	else
	{
		printf("%c n'est pas alpha-numérique.\n", testChar);
	}
	return 0;
}*/
