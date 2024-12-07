/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:38:34 by hni-xuan          #+#    #+#             */
/*   Updated: 2024/12/07 11:37:48 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

void	ft_free_arr(char **filtered_input, int len)
{
	while(len--)
		free(filtered_input[len]);
	free(filtered_input);
}

void	exit_error()
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

int	stack_size(t_stack **stack)
{
	int		count;
	t_stack	*temp;

	count = 0;
	temp = *stack;
	while(temp)
	{
		count++;
		temp = temp->next;	
	}
	return (count);
}

void	node_position(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = *stack;
	while(temp)
	{
		temp->pos = i++;
		temp = temp->next;
	}
}

void	free_node(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp_2;

	temp = *stack;
	while (temp)
	{
		temp_2 = temp;
		temp = temp->next;
		temp_2->next = NULL;
		free(temp_2);
	}
	free(temp);
}
