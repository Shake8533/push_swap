/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insert_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <palefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 05:21:14 by palefebv          #+#    #+#             */
/*   Updated: 2026/03/10 05:22:36 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_rr_part(t_stack **a, t_stack **b, int b_ra, int a_ra)
{
	int	common;

	if (b_ra < a_ra)
		common = b_ra;
	else
		common = a_ra;
	while (common-- > 0)
		rr(a, b);
}

static void	do_rrr_part(t_stack **a, t_stack **b, int b_rra, int a_rra)
{
	int	common;

	if (b_rra < a_rra)
		common = b_rra;
	else
		common = a_rra;
	while (common-- > 0)
		rrr(a, b);
}

void	do_combined(t_stack **a, t_stack **b, int b_pos, int a_pos)
{
	int	b_size;
	int	a_size;

	b_size = stack_size(*b);
	a_size = stack_size(*a);
	if (b_pos <= b_size - b_pos && a_pos <= a_size - a_pos)
		do_rr_part(a, b, b_pos, a_pos);
	else if (b_pos > b_size - b_pos && a_pos > a_size - a_pos)
		do_rrr_part(a, b, b_size - b_pos, a_size - a_pos);
}
