/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isaplha.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:40:27 by palefebv          #+#    #+#             */
/*   Updated: 2024/10/14 14:04:46 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
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
	if (ft_isalpha(testChar))
	{
		printf("%c est une lettre.\n", testChar);
	}
	else
	{
		printf("%c n'est pas une lettre.\n", testChar);
	}
	return 0;
}*/
