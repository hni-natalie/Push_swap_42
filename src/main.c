/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:17:35 by hni-xuan          #+#    #+#             */
/*   Updated: 2024/12/09 14:23:53 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**filtered_input;
	int		input_len;
	int		*arr;

	stack_a = NULL;
	stack_b = NULL;
	input_len = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	if (argc >= 2)
	{
		filtered_input = to_str_arr(argv + 1);
		input_len = check_input(filtered_input, &arr);
		stack_a = stack_init(arr, input_len);
		sort_index(&stack_a, input_len);
		push_swap(&stack_a, &stack_b, input_len);
		if (!is_sorted(&stack_a))
			sort_a(&stack_a);
		free_node(&stack_a);
		free(arr);
	}
}

char	**to_str_arr(char **argv)
{
	char	*new_str;
	int		i;
	char	**str_arr;

	i = 0;
	new_str = NULL;
	while (argv[i])
	{
		if (!argv[i][0])
		{
			free(new_str);
			exit_error();
		}
		new_str = ft_strjoin(new_str, argv[i++]);
		new_str = ft_strjoin(new_str, " ");
	}
	str_arr = ft_split(new_str, ' ');
	free(new_str);
	return (str_arr);
}

t_stack	*stack_init(int *arr, int len)
{
	int		i;
	t_stack	*stack;
	t_stack	*temp;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	temp = stack;
	i = -1;
	while (++i < len)
	{
		temp->value = arr[i];
		if ((i + 1) < len)
		{
			temp->next = malloc(sizeof(t_stack));
			if (!(temp -> next))
				return (NULL);
			temp = temp->next;
		}
		else
			temp->next = NULL;
	}
	return (stack);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (is_sorted(stack_a))
		return ;
	else if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size > 3)
		turk_sort(stack_a, stack_b);
}

void	sort_a(t_stack **stack_a)
{
	t_stack	*first;
	int		rotate_time;

	node_position(stack_a);
	first = *stack_a;
	while (first)
	{
		if (first->index == 0)
			break ;
		first = first->next;
	}
	if (first->pos > (stack_size(stack_a) / 2))
	{
		rotate_time = stack_size(stack_a) - first->pos;
		while (rotate_time--)
			rra(stack_a);
	}
	else
	{
		rotate_time = first->pos;
		while (rotate_time--)
			ra(stack_a);
	}
}
