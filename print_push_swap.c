/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <palefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 01:04:30 by palefebv          #+#    #+#             */
/*   Updated: 2025/02/05 01:04:30 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/ft_printf.h"

void	print_stacks(t_stack *a, t_stack *b, const char *operation)
{
	if (*operation)
		ft_printf("Exec %s:\n", operation);
	else
	{
		ft_printf("-----------------------------------------------------\n");
		ft_printf("Init a and b:\n");
	}
	ft_printf("a :");
	print_stack(a);
	ft_printf("b :");
	print_stack(b);
	ft_printf("---------------------------------------------------------\n");
}

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d ", stack->value);
		stack = stack->next;
	}
	ft_printf("\n");
}
