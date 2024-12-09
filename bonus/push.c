/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:20:30 by hni-xuan          #+#    #+#             */
/*   Updated: 2024/12/09 11:18:16 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*temp_src;

	if ((*src) == NULL)
		return ;
	temp_src = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = temp_src;
}

void	pa(t_stack	**stack_b, t_stack **stack_a)
{
	push(stack_b, stack_a);
}

void	pb(t_stack	**stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
}
