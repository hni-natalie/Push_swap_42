/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:51:10 by hni-xuan          #+#    #+#             */
/*   Updated: 2024/12/07 11:33:32 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

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
	ft_printf("pa\n");
}

void	pb(t_stack	**stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}