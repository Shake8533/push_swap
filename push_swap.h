/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <palefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 01:04:20 by palefebv          #+#    #+#             */
/*   Updated: 2025/02/05 01:04:20 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

void	push(t_stack **stack, int value);
int		is_nbr(char *str);
void	error_exit(t_stack **a);
int		has_duplicate(t_stack *stack, int value);
void	parse_args(int argc, char **argv, t_stack **a);
int		pop(t_stack **stack);
int		is_sorted(t_stack *stack);
void	sa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	ra(t_stack **a, t_stack **b);
void	push_min_to_b(t_stack **a, t_stack **b);
void	retrieve_sorted(t_stack **a, t_stack **b);
void	sort_stack(t_stack **a, t_stack **b);
void	free_stack(t_stack **stack);
void	print_stacks(t_stack *a, t_stack *b, const char *operation);
void	print_stack(t_stack *stack);

#endif
