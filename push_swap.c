/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <palefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 01:04:24 by palefebv          #+#    #+#             */
/*   Updated: 2025/02/05 01:04:24 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int operation_count = 0;

void count_operation(const char *op)
{
	operation_count++;
	printf("%s\n", op);
}

void	set_index(t_list *head, int link_size)
{
	t_list	*biggest;
	t_list	*tmp;

	while (link_size-- > 0)
	{
		biggest = NULL;
		tmp = head;
		while (tmp)
		{
			if (!tmp->index && (biggest == NULL
					|| tmp->value > biggest->value))
				biggest = tmp;
			tmp = tmp->next;
		}
		if (biggest)
			biggest->index = link_size;
	}
}

void print_stack(t_list *stack)
{
	while (stack)
	{
		printf("%d ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}

void	push(t_list **stack, int value)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		exit(EXIT_FAILURE);
	new_node->value = value;
	new_node->next = *stack;
	*stack = new_node;
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc < 2)
	{
		return (0);
	}
	a = NULL;
	b = NULL;
	operation_count = 0;
	parse_args(argc, argv, &a);
	set_index(a, count_nodes(a));
	sort_stack(&a, &b);
	printf("Total operations: %d\n", operation_count);
	print_stack(a);
	print_stack(b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
