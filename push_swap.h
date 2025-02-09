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

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_list;

void	push(t_list **stack, int value);
int		is_nbr(char *str);
void	error_exit(t_list **a);
int		has_duplicate(t_list *stack, int value);
void	parse_args(int argc, char **argv, t_list **a);
int		pop(t_list **stack);
//int		is_sorted(t_list *stack);

void	free_stack(t_list **stack);
//int		stack_size(t_list *stack);
void	print_stack(t_list *stack);

void	sa(t_list **a);
//void	sb(t_stack **b);
//void	ss(t_stack **a, t_stack **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
//void	rr(t_stack **a, t_stack **b);
void	rra(t_list **a);
void	rrb(t_list **b);
//void	rrr(t_stack **a, t_stack **b);

/*void push_swap(t_list **a, t_list **b);
int is_sorted(t_list **stack);
int stack_size(t_list *stack);
int	get_max_bits(t_list **stack);
void radix_sort(t_list **a, t_list **b, int	bit);
void radix_sortb(t_list **a, t_list **b, int	bit);
t_list	*find_largest(t_list *b);
void	move_to_top(t_list **b, t_list *largest);
//void push_sorted_b(t_list **a, t_list **b);
//void insert_sorted_a(t_list **a, t_list **b);*/

int	find_biggest(t_list *head);
int	find_bits(int biggest_nbr);
void	sort_three(t_list **head);
void	sort_five(t_list **stack_a, t_list **stack_b);
void	radix_sort(t_list **stack_a, t_list **stack_b);
void	sort_stack(t_list **stack_a, t_list **stack_b);
int	count_nodes(t_list *head);
int	sorted(t_list **head);

void	count_operation(const char *op);

#endif
