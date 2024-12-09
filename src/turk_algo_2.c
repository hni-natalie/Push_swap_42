/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:42:28 by hni-xuan          #+#    #+#             */
/*   Updated: 2024/12/09 11:12:25 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_node(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node_to_push;

	node_to_push = cheapest_node(stack_b);
	rotate_both(stack_a, stack_b, node_to_push);
	if (node_to_push->cost_a < 0)
		while (node_to_push->cost_a++ < 0)
			rra(stack_a);
	else if (node_to_push->cost_a > 0)
		while (node_to_push->cost_a-- > 0)
			ra(stack_a);
	if (node_to_push->cost_b < 0)
		while (node_to_push->cost_b++ < 0)
			rrb(stack_b);
	else if (node_to_push->cost_b > 0)
		while (node_to_push->cost_b-- > 0)
			rb(stack_b);
	pa(stack_b, stack_a);
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *node)
{
	if (node->cost_a < 0 && node->cost_b < 0)
	{
		while (node->cost_a < 0 && node->cost_b < 0)
		{
			rrr(stack_a, stack_b);
			node->cost_a++;
			node->cost_b++;
		}
	}
	else
	{
		while (node->cost_a > 0 && node->cost_b > 0)
		{
			rr(stack_a, stack_b);
			node->cost_a--;
			node->cost_b--;
		}
	}
}

t_stack	*cheapest_node(t_stack **stack_b)
{
	t_stack	*b;
	t_stack	*cheapest;

	b = *stack_b;
	cheapest = *stack_b;
	while (b)
	{
		if (total_cost(b) < total_cost(cheapest))
			cheapest = b;
		b = b->next;
	}
	return (cheapest);
}

int	total_cost(t_stack *current_node)
{
	int	cost;

	cost = 0;
	if (current_node->cost_a < 0)
		cost += current_node->cost_a * -1;
	else
		cost += current_node->cost_a;
	if (current_node->cost_b < 0)
		cost += current_node->cost_b * -1;
	else
		cost += current_node->cost_b;
	return (cost);
}
