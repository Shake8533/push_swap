/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdruel <hdruel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:03:51 by hdruel            #+#    #+#             */
/*   Updated: 2024/12/10 23:06:26 by hdruel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

int		count_arg(char **array);
int		check_doubles(char **argv);
int		check_nbr(char *argv);
int		sorted(t_stack **head);
int		check_move(char *input, t_stack **stack_a, t_stack **stack_b);
int		count_nodes(t_stack *head);
void	error_msg(char *str);
void	read_input(t_stack **stack_a, t_stack **stack_b);
void	swap(t_stack **head);
void	swap_ab(t_stack **stack_a, t_stack **stack_b);
void	rotate_up(t_stack **head);
void	rotate_ab(t_stack **stack_a, t_stack **stack_b);
void	rotate_down(t_stack **head);
void	r_rotate_ab(t_stack **stack_a, t_stack **stack_b);
void	push(t_stack **stack_from, t_stack **stack_to);
void	insert_at_tail(t_stack **head, int new_value);
void	free_stack(t_stack **head);
void	check_input(int argc, char **argv);
void	set_index(t_stack *head, int link_size);
t_stack	*init_list(int argc, char **argv);
t_stack	*make_new_node(int new_value);

#endif
