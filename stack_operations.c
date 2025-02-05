/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <palefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 01:03:50 by palefebv          #+#    #+#             */
/*   Updated: 2025/02/05 01:03:50 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/ft_printf.h"

void	sa(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*a = second;
	ft_printf("sa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	if (!*a)
		return ;
	push(b, pop(a));
	ft_printf("pb\n");
}

void	pa(t_stack **a, t_stack **b)
{
	if (!*b)
		return ;
	push(a, pop(b));
	ft_printf("pa\n");
}

void	ra(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	last = *a;
	while (last->next)
		last = last->next;
	*a = first->next;
	first->next = NULL;
	last->next = first;
	ft_printf("ra\n");
}
