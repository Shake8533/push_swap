/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <palefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 00:41:21 by palefebv          #+#    #+#             */
/*   Updated: 2026/03/10 05:25:23 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	apply_insert(t_stack **a, t_stack **b, int chosen)
{
	int	b_pos;
	int	a_pos;

	b_pos = pos_of(*b, chosen);
	a_pos = target_in_a(*a, chosen);
	do_combined(a, b, b_pos, a_pos);
	bring_top_b(b, pos_of(*b, chosen));
	bring_top_a(a, target_in_a(*a, chosen));
	pa(a, b);
}

void	insert_max_first(t_stack **a, t_stack **b)
{
	while (*b)
		apply_insert(a, b, max_idx(*b));
}

void	insert_greedy(t_stack **a, t_stack **b)
{
	while (*b)
		apply_insert(a, b, best_to_insert(*b, *a));
}
