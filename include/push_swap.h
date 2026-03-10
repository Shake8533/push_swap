/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <palefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 05:24:52 by palefebv          #+#    #+#             */
/*   Updated: 2026/03/10 05:36:39 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

/* check.c */
void	push(t_stack **stack, int value);
int		is_nbr(char *str);
void	error_exit(t_stack **a);
int		has_duplicate(t_stack *stack, int value);
void	parse_args(int argc, char **argv, t_stack **a);

/* utils.c */
int		count_nodes(t_stack *stack);
void	free_stack(t_stack **stack);

/* sort_util.c */
int		find_biggest(t_stack *stack);
int		sorted(t_stack **stack);

/* sort_util2.c */
int		stack_size(t_stack *s);
int		pos_of(t_stack *s, int idx);
int		max_idx(t_stack *s);
int		min_idx(t_stack *s);
void	bring_top_a(t_stack **a, int pos);

/* sort_util3.c */
void	bring_top_b(t_stack **b, int pos);
int		rot_cost(int pos, int size);
int		target_in_a(t_stack *a, int b_idx);
int		total_cost(int b_pos, int b_size, int a_pos, int a_size);

/* sort_cost.c */
int		best_to_insert(t_stack *b, t_stack *a);

/* sort_chunk.c */
void	phase_push_to_b(t_stack **a, t_stack **b, int cs);
int		chunk_size_small(int n);
int		chunk_size_large(int n);

/* sort_insert.c */
void	insert_max_first(t_stack **a, t_stack **b);
void	insert_greedy(t_stack **a, t_stack **b);

/* sort_insert.c */
void	do_combined(t_stack **a, t_stack **b, int b_pos, int a_pos);

/* sort_stack.c */
void	final_rotate(t_stack **a);
void	sort_stack(t_stack **a, t_stack **b);

/* swap.c */
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

/* rotate.c */
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

/* rev_rotate.c */
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/* push_rotate.c */
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

#endif
