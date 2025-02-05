/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <palefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 01:04:37 by palefebv          #+#    #+#             */
/*   Updated: 2025/02/05 01:04:37 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pop(t_stack **stack)
{
	int		value;
	t_stack	*temp;

	if (!*stack)
		return (0);
	temp = *stack;
	value = temp->value;
	*stack = temp->next;
	free(temp);
	return (value);
}

void	free_stack(t_stack **stack)
{
	while (*stack)
		pop(stack);
}
