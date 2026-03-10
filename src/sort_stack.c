/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <palefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 05:28:42 by palefebv          #+#    #+#             */
/*   Updated: 2026/03/10 05:28:44 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three_tail(t_stack **a, int a1, int a2, int a3)
{
	if (a1 > a2 && a1 < a3)
	{
		sa(a);
		return ;
	}
	if (a1 > a2 && a1 > a3 && a2 < a3)
	{
		ra(a);
		return ;
	}
	if (a1 < a2 && a2 > a3 && a1 < a3)
	{
		rra(a);
		sa(a);
		return ;
	}
	rra(a);
}

static void	sort_three(t_stack **a)
{
	int	a1;
	int	a2;
	int	a3;

	a1 = (*a)->index;
	a2 = (*a)->next->index;
	a3 = (*a)->next->next->index;
	if (a1 < a2 && a2 < a3)
		return ;
	if (a1 > a2 && a2 > a3)
	{
		sa(a);
		rra(a);
		return ;
	}
	sort_three_tail(a, a1, a2, a3);
}

static void	sort_small(t_stack **a, t_stack **b)
{
	int	size;
	int	pushed;

	size = stack_size(*a);
	pushed = 0;
	while (pushed < size - 3)
	{
		if ((*a)->index < size - 3)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a);
	}
	sort_three(a);
	insert_max_first(a, b);
	final_rotate(a);
}

void	final_rotate(t_stack **a)
{
	int	min_pos;

	min_pos = pos_of(*a, min_idx(*a));
	while ((*a)->index != 0)
	{
		if (min_pos <= stack_size(*a) / 2)
			ra(a);
		else
			rra(a);
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	n;

	if (sorted(a))
		return ;
	n = stack_size(*a);
	if (n == 2 && (*a)->index > (*a)->next->index)
		return (sa(a));
	if (n == 3)
		return (sort_three(a));
	if (n <= 5)
		return (sort_small(a, b));
	if (n <= 100)
		phase_push_to_b(a, b, chunk_size_small(n));
	else
		phase_push_to_b(a, b, chunk_size_large(n));
	if (n <= 100)
		insert_max_first(a, b);
	else
		insert_greedy(a, b);
	final_rotate(a);
}
