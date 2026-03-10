/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <palefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 00:41:21 by palefebv          #+#    #+#             */
/*   Updated: 2026/03/10 05:38:22 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	scan_best_cost(t_stack *b, t_stack *a, int b_size, int a_size)
{
	int		best_cost;
	int		b_pos;

	best_cost = INT_MAX;
	b_pos = 0;
	while (b)
	{
		if (total_cost(b_pos, b_size, target_in_a(a, b->index), a_size)
			< best_cost)
			best_cost = total_cost(b_pos, b_size,
					target_in_a(a, b->index), a_size);
		b = b->next;
		b_pos++;
	}
	return (best_cost);
}

int	best_to_insert(t_stack *b, t_stack *a)
{
	t_stack	*tmp;
	int		b_size;
	int		a_size;
	int		best_cost;
	int		b_pos;

	b_size = stack_size(b);
	a_size = stack_size(a);
	best_cost = scan_best_cost(b, a, b_size, a_size);
	tmp = b;
	b_pos = 0;
	while (tmp)
	{
		if (total_cost(b_pos, b_size,
				target_in_a(a, tmp->index), a_size) == best_cost)
			return (tmp->index);
		tmp = tmp->next;
		b_pos++;
	}
	return (max_idx(b));
}
