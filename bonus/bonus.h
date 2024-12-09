/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:17:22 by hni-xuan          #+#    #+#             */
/*   Updated: 2024/12/09 11:18:33 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "../libft/gnl/get_next_line.h"
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

int		is_sorted(t_stack **stack);

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
void	label_index(t_stack *temp, int *arr);
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