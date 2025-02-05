/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 21:42:02 by palefebv          #+#    #+#             */
/*   Updated: 2024/10/21 21:42:36 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}
/*
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	// Test 1: Ecrire dans la sortie standard (fd = 1)
	ft_putendl_fd("Hello, world!", 1);

	// Test 2: Ecrire dans un fichier
	int fd = open("test_file.txt", O_RDWR | O_CREAT, 0644);
	if (fd == -1)
	{
		printf("Erreur lors de l'ouverture du fichier.\n");
		return (1);
	}

	ft_putendl_fd("Ceci est un test.", fd);

	close(fd);

	return (0);
}*/
