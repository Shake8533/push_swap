/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <palefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 00:41:21 by palefebv          #+#    #+#             */
/*   Updated: 2026/03/10 05:37:47 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *s)
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

int	pos_of(t_stack *s, int idx)
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

int	max_idx(t_stack *s)
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

int	min_idx(t_stack *s)
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

void	bring_top_a(t_stack **a, int pos)
{
	int	size;

	if (pos == 0)
		return ;
	size = stack_size(*a);
	if (size == 0)
		return ;
	if (pos <= size - pos)
		while (pos-- > 0)
			ra(a);
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(a);
	}
}
