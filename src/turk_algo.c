/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 09:37:32 by hni-xuan          #+#    #+#             */
/*   Updated: 2024/12/09 11:14:13 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turk_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	len_to_push;

	push_to_b(stack_a, stack_b);
	sort_three(stack_a);
	len_to_push = stack_size(stack_b);
	while (len_to_push--)
	{
		node_position(stack_a);
		node_position(stack_b);
		find_cost(stack_a, stack_b);
		push_node(stack_a, stack_b);
	}
}

void	push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int		half_size;
	int		len_to_push;
	int		i;
	t_stack	*temp;

	half_size = stack_size(stack_a) / 2;
	len_to_push = stack_size(stack_a) - 3;
	i = 0;
	while (i < (len_to_push / 2))
	{
		temp = *stack_a;
		if (temp->index >= half_size)
			ra(stack_a);
		else
		{
			pb(stack_a, stack_b);
			i++;
		}
	}
	while (i++ < len_to_push)
		pb(stack_a, stack_b);
}

void	find_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b;
	t_stack	*target_node;

	b = *stack_b;
	while (b)
	{
		target_node = get_target(stack_a, b->value);
		if (target_node->pos > (stack_size(stack_a) / 2))
			b->cost_a = target_node->pos - stack_size(stack_a);
		else
			b->cost_a = target_node->pos;
		if (b->pos > (stack_size(stack_b) / 2))
			b->cost_b = b->pos - stack_size(stack_b);
		else
			b->cost_b = b->pos;
		b = b->next;
	}
}

t_stack	*get_target(t_stack **stack_a, int current_num)
{
	t_stack	*a;
	t_stack	*target;

	a = *stack_a;
	target = NULL;
	while (a)
	{
		if (target)
		{
			if (a->value < target->value && current_num < a->value)
				target = a;
		}
		else if (current_num < a->value)
			target = a;
		a = a->next;
	}
	if (!target)
		target = get_smallest(stack_a);
	return (target);
}

t_stack	*get_smallest(t_stack **stack_a)
{
	t_stack	*a;
	t_stack	*smallest;

	a = *stack_a;
	smallest = *stack_a;
	while (a)
	{
		if (a->value < smallest->value)
			smallest = a;
		a = a->next;
	}
	return (smallest);
}
