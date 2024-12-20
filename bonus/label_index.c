/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:42:04 by hni-xuan          #+#    #+#             */
/*   Updated: 2024/12/09 16:29:48 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

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
	temp = *stack;
	label_index(temp, sorted_arr);
	free(sorted_arr);
}

void	label_index(t_stack *temp, int *arr)
{
	int		i;

	i = 0;
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
