/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:43:26 by palefebv          #+#    #+#             */
/*   Updated: 2024/10/21 20:45:14 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Fonction de test qui va modifier chaque caractère en majuscule
void	to_uppercase(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

// Fonction de test qui remplace chaque caractère par '*'
void	to_asterisk(unsigned int i, char *c)
{
	(void)i;
	*c = '*';
}

// Fonction de test qui affiche l'index et le caractère
void	print_index_and_char(unsigned int i, char *c)
{
	printf("Index %u: %c\n", i, *c);
}

// Fonction de test qui vérifie si l'index est pair et met en majuscule si oui
void	uppercase_even_index(unsigned int i, char *c)
{
	if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
		*c -= 32;
}

int main(void)
{
	char	str1[] = "hello";
	char	str2[] = "world";
	char	str3[] = "Test String!";
	char	*str_null = NULL;

	// Test 1: Transformer chaque caractère en majuscule
	printf("Test 1: To uppercase\n");
	ft_striteri(str1, to_uppercase);
	printf("Result: %s\n\n", str1); // Attendu: "HELLO"

	// Test 2: Remplacer chaque caractère par un astérisque
	printf("Test 2: Replace with asterisk\n");
	ft_striteri(str2, to_asterisk);
	printf("Result: %s\n\n", str2); // Attendu: "*****"

	// Test 3: Afficher l'index et le caractère
	printf("Test 3: Print index and char\n");
	ft_striteri(str3, print_index_and_char);
	printf("Result: %s\n\n", str3);

	// Test 4: Mettre en majuscule les caractères à index pair
	printf("Test 4: Uppercase even index\n");
	ft_striteri(str3, uppercase_even_index);
	printf("Result: %s\n\n", str3); // Attendu: "TeSt StRiNg!"

	// Test 5: Chaîne nulle
	printf("Test 5: Null string\n");
	ft_striteri(str_null, to_uppercase); // Ne doit rien se passer, pas de crash

	return (0);
}*/
