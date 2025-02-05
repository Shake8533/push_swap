/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:49:40 by palefebv          #+#    #+#             */
/*   Updated: 2024/10/21 20:52:00 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		ft_putchar_fd(n + '0', fd);
	}
}
/*
#include <fcntl.h>
#include <stdio.h>
int main(void)
{
	int	fd;

	// Test 1: Affichage sur la sortie standard (stdout)
	printf("Test 1: Affichage dans la console\n");
	ft_putnbr_fd(42, 1); // Affiche "42"
	write(1, "\n", 1);
	ft_putnbr_fd(-42, 1); // Affiche "-42"
	write(1, "\n", 1);
	ft_putnbr_fd(2147483647, 1); // Affiche "2147483647"
	write(1, "\n", 1);
	ft_putnbr_fd(-2147483648, 1); // Affiche "-2147483648"
	write(1, "\n", 1);

	// Test 2: Affichage dans un fichier
	fd = open("test_putnbr.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("Erreur à l'ouverture du fichier");
		return (1);
	}
	printf("\nTest 2: Affichage dans le fichier 'test_putnbr.txt'\n");
	ft_putnbr_fd(123456, fd); // Écrit "123456" dans le fichier
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(-987654, fd); // Écrit "-987654" dans le fichier
	ft_putchar_fd('\n', fd);
	close(fd);

	// Test 3: Cas limite avec zéro
	printf("\nTest 3: Affichage de 0 dans la console\n");
	ft_putnbr_fd(0, 1); // Affiche "0"
	write(1, "\n", 1);

	return (0);
}*/
