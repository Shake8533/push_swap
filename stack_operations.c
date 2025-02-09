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


void	sa(t_list **a)
{
	if (!*a && !(*a)->next)
		return ;
	t_list *first = *a;
	t_list *second = first->next;
	first->next = second->next;
	second->next = first;
	*a = second;
	ft_printf("sa\n");
	count_operation("sa");
}
/*
void	sb(t_stack **b)
{
	sa(b);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sa(b);
}
*/
void	pb(t_list **a, t_list **b)
{
	if (!*a)
		return ;
	push(b, pop(a));
	ft_printf("pb\n");
	count_operation("pb");
}

void	pa(t_list **a, t_list **b)
	{
		if (!*b)
		return ;
	push(a, pop(b));
	ft_printf("pa\n");
	count_operation("pa");
	}

void	ra(t_list **a)
{
t_list	*first;
t_list	*last;

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
	count_operation("ra");
}

void	rb(t_list **b)
{
	t_list	*first;
	t_list	*last;

	if (!*b || !(*b)->next)
		return ;
	first = *b;
	last = *b;
	while (last->next)
		last = last->next;
	*b = first->next;
	first->next = NULL;
	last->next = first;
	ft_printf("rb\n");
	count_operation("rb");
}

/*
void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	ra(b);
}
*/
void	rra(t_list **a)
{
	t_list	*prev;
	t_list	*last;

	if (!*a || !(*a)->next)
		return ;
	prev = NULL;
	last = *a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *a;
	*a = last;
	ft_printf("rra\n");
	count_operation("rra");
}

void	rrb(t_list **b)
{
	t_list	*prev;
	t_list	*last;

	if (!*b || !(*b)->next)
		return ;
	prev = NULL;
	last = *b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *b;
	*b = last;
	ft_printf("rrb\n");
	count_operation("rrb");
}

/*
void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rra(b);
}
*/