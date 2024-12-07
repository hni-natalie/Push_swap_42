/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:42:04 by hni-xuan          #+#    #+#             */
/*   Updated: 2024/12/06 18:22:22 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

/* static void	debug_stack(t_stack **stack)
{
	t_stack *current = *stack;
	while (current != NULL)
	{
		printf("%d -> ", current->value);
		current = current->next;
	}
	printf("NULL\n");
} */


void	sort_index(t_stack **stack, int len)
{
	t_stack	*temp;
	int		i;
	int		*sorted_arr;

	temp = *stack;
	i = 0;
	sorted_arr = malloc(sizeof(int) * len);
	if(!sorted_arr)
		return ;
	while (temp)
	{
		sorted_arr[i++] = temp->value;
		temp = temp->next;
	}
	bubble_sort(sorted_arr, len);
	// for (int i = 0; i < len; i++)
	// 	printf("%d ", sorted_arr[i]);
	// printf("\n");
	temp = *stack;
	label_index(temp, sorted_arr);
	// debug_stack(stack);  // debug
	free(sorted_arr);
}

void	label_index(t_stack *temp, int *arr)
{
	int		i;

	i = 0;
	while (temp)
	{
		while (arr[i])
		{
			if (arr[i] == temp->value)
			{
				temp->index = i;
				i = 0;
				break;
			}
			i++;
		}
		temp = temp->next;
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
