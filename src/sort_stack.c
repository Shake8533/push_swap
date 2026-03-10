/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <palefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 00:40:59 by palefebv          #+#    #+#             */
/*   Updated: 2026/03/10 04:46:45 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_size(t_stack *s)
{
	int	n;

	n = 0;
	while (s)
	{
		s = s->next;
		n++;
	}
	return (n);
}

static int	pos_of(t_stack *s, int idx)
{
	int	pos;

	pos = 0;
	while (s)
	{
		if (s->index == idx)
			return (pos);
		s = s->next;
		pos++;
	}
	return (0);
}

static int	max_idx(t_stack *s)
{
	int	m;

	m = -1;
	while (s)
	{
		if (s->index > m)
			m = s->index;
		s = s->next;
	}
	return (m);
}

static int	min_idx(t_stack *s)
{
	int	m;

	m = INT_MAX;
	while (s)
	{
		if (s->index < m)
			m = s->index;
		s = s->next;
	}
	return (m);
}

static int	rot_cost(int pos, int size)
{
	if (size == 0 || pos == 0)
		return (0);
	if (pos <= size - pos)
		return (pos);
	return (size - pos);
}

static int	prefer_ra(int pos, int size)
{
	return (pos <= size - pos);
}

static void	bring_top_a(t_stack **a, int pos)
{
	int	size;

	if (pos == 0)
		return ;
	size = stack_size(*a);
	if (size == 0)
		return ;
	if (prefer_ra(pos, size))
		while (pos-- > 0)
			ra(a);
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(a);
	}
}

static void	bring_top_b(t_stack **b, int pos)
{
	int	size;

	if (pos == 0)
		return ;
	size = stack_size(*b);
	if (size == 0)
		return ;
	if (prefer_ra(pos, size))
		while (pos-- > 0)
			rb(b);
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rrb(b);
	}
}

static int	target_in_a(t_stack *a, int b_idx)
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

static int	chunk_size_small(int n)
{
	if (n <= 10)
		return (4);
	if (n <= 40)
		return (8);
	return (20);
}

static int	chunk_size_large(int n)
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

static void	phase_push_to_b(t_stack **a, t_stack **b, int cs)
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

static void	insert_max_first(t_stack **a, t_stack **b)
{
	int	chosen;
	int	b_pos;
	int	a_pos;
	int	b_size;
	int	a_size;
	int	b_ra;
	int	b_rra;
	int	a_ra;
	int	a_rra;
	int	common;

	while (*b)
	{
		chosen = max_idx(*b);
		b_pos  = pos_of(*b, chosen);
		a_pos  = target_in_a(*a, chosen);
		b_size = stack_size(*b);
		a_size = stack_size(*a);
		b_ra   = b_pos;
		b_rra  = (b_pos == 0) ? 0 : b_size - b_pos;
		a_ra   = a_pos;
		a_rra  = (a_pos == 0) ? 0 : a_size - a_pos;
		if (b_ra <= b_rra && a_ra <= a_rra)
		{
			common = (b_ra < a_ra) ? b_ra : a_ra;
			while (common-- > 0)
				rr(a, b);
		}
		else if (b_rra < b_ra && a_rra < a_ra)
		{
			common = (b_rra < a_rra) ? b_rra : a_rra;
			while (common-- > 0)
				rrr(a, b);
		}
		b_pos = pos_of(*b, chosen);
		a_pos = target_in_a(*a, chosen);
		bring_top_b(b, b_pos);
		bring_top_a(a, a_pos);
		pa(a, b);
	}
}

static int	total_cost(int b_pos, int b_size, int a_pos, int a_size)
{
	int	rb;
	int	ra_c;

	rb   = rot_cost(b_pos, b_size);
	ra_c = rot_cost(a_pos, a_size);
	if (prefer_ra(b_pos, b_size) == prefer_ra(a_pos, a_size))
	{
		if (rb > ra_c)
			return (rb + 1);
		return (ra_c + 1);
	}
	return (rb + ra_c + 1);
}

static int	best_to_insert(t_stack *b, t_stack *a)
{
	t_stack	*tmp;
	int		b_size;
	int		a_size;
	int		best_idx;
	int		best_cost;
	int		cost;
	int		b_pos;
	int		a_pos;

	b_size = stack_size(b);
	a_size = stack_size(a);
	best_cost = INT_MAX;
	best_idx = max_idx(b);
	tmp = b;
	b_pos = 0;
	while (tmp)
	{
		a_pos = target_in_a(a, tmp->index);
		cost = total_cost(b_pos, b_size, a_pos, a_size);
		if (cost < best_cost)
		{
			best_cost = cost;
			best_idx = tmp->index;
		}
		tmp = tmp->next;
		b_pos++;
	}
	return (best_idx);
}

static void	insert_greedy(t_stack **a, t_stack **b)
{
	int	chosen;
	int	b_pos;
	int	a_pos;
	int	b_size;
	int	a_size;
	int	b_ra;
	int	b_rra;
	int	a_ra;
	int	a_rra;
	int	common;

	while (*b)
	{
		chosen = best_to_insert(*b, *a);
		b_pos  = pos_of(*b, chosen);
		a_pos  = target_in_a(*a, chosen);
		b_size = stack_size(*b);
		a_size = stack_size(*a);
		b_ra   = b_pos;
		b_rra  = (b_pos == 0) ? 0 : b_size - b_pos;
		a_ra   = a_pos;
		a_rra  = (a_pos == 0) ? 0 : a_size - a_pos;
		if (b_ra <= b_rra && a_ra <= a_rra)
		{
			common = (b_ra < a_ra) ? b_ra : a_ra;
			while (common-- > 0)
				rr(a, b);
		}
		else if (b_rra < b_ra && a_rra < a_ra)
		{
			common = (b_rra < a_rra) ? b_rra : a_rra;
			while (common-- > 0)
				rrr(a, b);
		}
		b_pos = pos_of(*b, chosen);
		a_pos = target_in_a(*a, chosen);
		bring_top_b(b, b_pos);
		bring_top_a(a, a_pos);
		pa(a, b);
	}
}

static void	sort_two(t_stack **a)
{
	if ((*a)->index > (*a)->next->index)
		sa(a);
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
	{ sa(a); rra(a); return ; }
	if (a1 > a2 && a1 < a3)
	{ sa(a); return ; }
	if (a1 > a2 && a1 > a3 && a2 < a3)
	{ ra(a); return ; }
	if (a1 < a2 && a2 > a3 && a1 < a3)
	{ rra(a); sa(a); return ; }
	rra(a);
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
	while ((*a)->index != 0)
	{
		if (pos_of(*a, 0) <= stack_size(*a) / 2)
			ra(a);
		else
			rra(a);
	}
}

static void	final_rotate(t_stack **a)
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
	if (n == 2)
		return (sort_two(a));
	if (n == 3)
		return (sort_three(a));
	if (n <= 5)
		return (sort_small(a, b));
	if (n <= 100)
	{
		phase_push_to_b(a, b, chunk_size_small(n));
		insert_max_first(a, b);
	}
	else
	{
		phase_push_to_b(a, b, chunk_size_large(n));
		insert_greedy(a, b);
	}
	final_rotate(a);
}
