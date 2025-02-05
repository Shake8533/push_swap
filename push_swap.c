/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <palefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 01:04:24 by palefebv          #+#    #+#             */
/*   Updated: 2025/02/05 01:04:24 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	push(t_stack **stack, int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		exit(EXIT_FAILURE);
	new_node->value = value;
	new_node->next = *stack;
	*stack = new_node;
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
	{
		return (0);
	}
	a = NULL;
	b = NULL;
	parse_args(argc, argv, &a);
	print_stacks(a, b, "");
	sort_stack(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
