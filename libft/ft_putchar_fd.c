/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:46:07 by palefebv          #+#    #+#             */
/*   Updated: 2024/10/21 21:01:13 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
#include <fcntl.h>
#include <stdio.h>
int main(void)
{
	int	fd;

	// Test 1: Affichage sur la sortie standard (stdout)
	printf("Test 1: Affichage dans la console\n");
	ft_putchar_fd('A', 1); // Affiche 'A'
	ft_putchar_fd('\n', 1); // Retour à la ligne
	ft_putchar_fd('z', 1); // Affiche 'z'
	ft_putchar_fd('\n', 1); // Retour à la ligne
	ft_putchar_fd('0', 1); // Affiche '0'
	ft_putchar_fd('\n', 1); // Retour à la ligne

	// Test 2: Écriture dans un fichier
	fd = open("test_putchar.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("Erreur à l'ouverture du fichier");
		return (1);
	}
	printf("\nTest 2: Écriture dans le fichier 'test_putchar.txt'\n");
	ft_putchar_fd('H', fd); // Écrit 'H' dans le fichier
	ft_putchar_fd('e', fd); // Écrit 'e' dans le fichier
	ft_putchar_fd('l', fd); // Écrit 'l' dans le fichier
	ft_putchar_fd('l', fd); // Écrit 'l' dans le fichier
	ft_putchar_fd('o', fd); // Écrit 'o' dans le fichier
	ft_putchar_fd('\n', fd); // Écrit un retour à la ligne
	close(fd);

	// Test 3: Cas limite avec des caractères spéciaux
	printf("\nTest 3: Affichage de caractères spéciaux dans la console\n");
	ft_putchar_fd('\n', 1); // Affiche un retour à la ligne
	ft_putchar_fd('\t', 1); // Affiche une tabulation
	ft_putchar_fd('\n', 1); // Retour à la ligne
	ft_putchar_fd(127, 1); // Affiche le caractère ASCII 127 (DEL)
	ft_putchar_fd('\n', 1); // Retour à la ligne

	return (0);
}*/
