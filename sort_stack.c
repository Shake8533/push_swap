/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <palefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 01:04:15 by palefebv          #+#    #+#             */
/*   Updated: 2025/02/05 01:04:15 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	push_min_to_b(t_stack **a, t_stack **b)
{
	int		min;
	t_stack	*temp;

	min = (*a)->value;
	temp = *a;
	while (temp)
	{
		if (temp->value < min)
			min = temp->value;
		temp = temp->next;
	}
	while ((*a)->value != min)
	{
		if ((*a)->next && (*a)->value > (*a)->next->value)
			sa(a);
		else
			ra(a);
	}
	pb(a, b);
}

void	retrieve_sorted(t_stack **a, t_stack **b)
{
	while (*b)
		pa(a, b);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	while (!is_sorted(*a))
		push_min_to_b(a, b);
	retrieve_sorted(a, b);
}
