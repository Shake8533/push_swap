/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 21:38:45 by palefebv          #+#    #+#             */
/*   Updated: 2024/10/21 21:40:26 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}
/*
#include <fcntl.h>

int	main(void)
{
	int	fd;

	// Ouvre un fichier en mode écriture. 
	//Si le fichier n'existe pas, il sera créé.
	fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
	{
		// Si l'ouverture échoue, affiche 
		//un message d'erreur et quitte le programme.
		ft_putstr_fd("Erreur lors de l'ouverture du fichier\n", 2);
		return (1);
	}

	// Test de la fonction avec une chaîne de caractères
	ft_putstr_fd("Bonjour, ceci est un test de ft_putstr_fd!\n", fd);

	// Ferme le fichier
	close(fd);

	return (0);
}*/
