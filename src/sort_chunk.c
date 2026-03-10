/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <palefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 05:31:50 by palefebv          #+#    #+#             */
/*   Updated: 2026/03/10 05:31:51 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chunk_size_small(int n)
{
	if (n <= 10)
		return (4);
	if (n <= 40)
		return (8);
	return (20);
}

int	chunk_size_large(int n)
{
	if (n <= 200)
		return (25);
	if (n <= 500)
		return (45);
	return (60);
}

static void	push_chunk(t_stack **a, t_stack **b, int lo, int hi)
{
	int	mid;
	int	to_push;
	int	scanned;
	int	orig_size;

	mid = (lo + hi) / 2;
	to_push = hi - lo + 1;
	orig_size = stack_size(*a);
	scanned = 0;
	while (to_push > 0 && scanned < orig_size)
	{
		if ((*a)->index >= lo && (*a)->index <= hi)
		{
			pb(a, b);
			if ((*b)->index > mid)
				rb(b);
			to_push--;
			orig_size--;
		}
		else
		{
			ra(a);
			scanned++;
		}
	}
}

void	phase_push_to_b(t_stack **a, t_stack **b, int cs)
{
	int	n;
	int	lo;
	int	hi;

	n = stack_size(*a);
	lo = 0;
	while (lo < n)
	{
		hi = lo + cs - 1;
		if (hi >= n)
			hi = n - 1;
		push_chunk(a, b, lo, hi);
		lo += cs;
	}
}
