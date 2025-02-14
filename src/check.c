/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <palefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 00:40:01 by palefebv          #+#    #+#             */
/*   Updated: 2025/02/14 01:20:24 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	is_nbr(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if ((result * sign) < INT_MIN || (result * sign) > INT_MAX)
		return (0);
	return (1);
}

void	error_exit(t_stack **a)
{
	write(2, "Error\n", 6);
	free_stack(a);
	exit(EXIT_FAILURE);
}

int	has_duplicate(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	parse_args(int argc, char **argv, t_stack **a)
{
	int	value;

	while (--argc)
	{
		if (!is_nbr(argv[argc]) || ft_strlen(argv[argc]) > 11)
			error_exit(a);
		value = ft_atoi(argv[argc]);
		if (has_duplicate(*a, (int)value))
			error_exit(a);
		push(a, value);
	}
}
