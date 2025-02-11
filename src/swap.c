/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 01:57:59 by palefebv          #+#    #+#             */
/*   Updated: 2025/02/11 01:58:01 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/ft_printf.h"

void	swap(t_stack **stack)
{
	if (!*stack && !(*stack)->next)
		return ;
	t_stack *first = *stack;
	t_stack *second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_stack **a)
{
    swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	swap(b);
    ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
    ft_printf("ss\n");
}
