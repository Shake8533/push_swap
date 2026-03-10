/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <palefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 00:41:21 by palefebv          #+#    #+#             */
/*   Updated: 2026/03/10 05:37:53 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bring_top_b(t_stack **b, int pos)
{
	int	size;

	if (pos == 0)
		return ;
	size = stack_size(*b);
	if (size == 0)
		return ;
	if (pos <= size - pos)
		while (pos-- > 0)
			rb(b);
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rrb(b);
	}
}

int	rot_cost(int pos, int size)
{
	if (size == 0 || pos == 0)
		return (0);
	if (pos <= size - pos)
		return (pos);
	return (size - pos);
}

int	target_in_a(t_stack *a, int b_idx)
{
	t_stack	*tmp;
	int		pos;
	int		best_pos;
	int		best_val;

	if (!a)
		return (0);
	tmp = a;
	pos = 0;
	best_pos = -1;
	best_val = INT_MAX;
	while (tmp)
	{
		if (tmp->index > b_idx && tmp->index < best_val)
		{
			best_val = tmp->index;
			best_pos = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	if (best_pos == -1)
		best_pos = pos_of(a, min_idx(a));
	return (best_pos);
}

int	total_cost(int b_pos, int b_size, int a_pos, int a_size)
{
	int	rb;
	int	ra_c;

	rb = rot_cost(b_pos, b_size);
	ra_c = rot_cost(a_pos, a_size);
	if ((b_pos <= b_size - b_pos) == (a_pos <= a_size - a_pos))
	{
		if (rb > ra_c)
			return (rb + 1);
		return (ra_c + 1);
	}
	return (rb + ra_c + 1);
}
