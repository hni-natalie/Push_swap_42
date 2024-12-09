/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:10:54 by hni-xuan          #+#    #+#             */
/*   Updated: 2024/12/09 14:29:54 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int				index;
	int				value;
	int				pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

// main function
char	**to_str_arr(char **num);
t_stack	*stack_init(int *arr, int len);
void	sort_a(t_stack **stack_a);

// push swap
void	push_swap(t_stack **stack_a, t_stack **stack_b, int size);
int		is_sorted(t_stack **stack);
void	sort_three(t_stack **stack_a);

// turk algorithm
void	turk_sort(t_stack **stack_a, t_stack **stack_b);
void	push_to_b(t_stack **stack_a, t_stack **stack_b);

void	find_cost(t_stack **stack_a, t_stack **stack_b);
t_stack	*get_target(t_stack **stack_a, int current_num);
t_stack	*get_smallest(t_stack **stack_a);

void	push_node(t_stack **stack_a, t_stack **stack_b);
t_stack	*cheapest_node(t_stack **stack_b);
int		total_cost(t_stack *current_node);
void	rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *node);

// swap
void	swap(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

// rotate
void	rotate(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

// reverse rotate
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

// push
void	push(t_stack **src, t_stack **dest);
void	pa(t_stack	**stack_b, t_stack **stack_a);
void	pb(t_stack	**stack_a, t_stack **stack_b);

// add index for each node 
void	label_index(t_stack **stack, int *arr);
void	bubble_sort(int *arr, int len);
void	sort_index(t_stack **stk, int len);

// check input
int		counts_word(char **input);
long	ft_atol(char *char_num);
void	check_duplicate(int *arr, int input_len);
int		non_int(char *input);
int		check_input(char **filtered_input, int **arr);

// utils
void	exit_error(void);
void	ft_free_arr(char **filtered_input, int len);
int		stack_size(t_stack **stack);
void	node_position(t_stack **stack);
void	free_node(t_stack **stack);

// bonus
void	checker(t_stack **a, t_stack **b);
void	check_step(t_stack **a, t_stack **b, char *s);

#endif