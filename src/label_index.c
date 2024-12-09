/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:42:04 by hni-xuan          #+#    #+#             */
/*   Updated: 2024/12/09 16:24:53 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_index(t_stack **stack, int len)
{
	t_stack	*temp;
	int		i;
	int		*sorted_arr;

	temp = *stack;
	i = 0;
	sorted_arr = malloc(sizeof(int) * len);
	if (!sorted_arr)
		return ;
	while (temp)
	{
		sorted_arr[i++] = temp->value;
		temp = temp->next;
	}
	bubble_sort(sorted_arr, len);
	label_index(stack, sorted_arr);
	free(sorted_arr);
}

void	label_index(t_stack **stack, int *arr)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = *stack;
	while (temp)
	{
		if (arr[i] == temp->value)
		{
			temp->index = i;
			temp = temp->next;
			i = 0;
		}
		else
			i++;
	}
}

void	bubble_sort(int *arr, int len)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < (len - 1))
	{
		j = i;
		while (++j < len)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
