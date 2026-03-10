/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <palefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 00:41:21 by palefebv          #+#    #+#             */
/*   Updated: 2025/02/19 00:20:04 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	find_biggest(t_stack *stack)
{
	int		big;
	t_stack	*tmp;

	big = INT_MIN;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index > big)
			big = tmp->index;
		tmp = tmp->next;
	}
	return (big);
}

int	sorted(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp && tmp->next)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
