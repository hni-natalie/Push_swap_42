/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:17:35 by hni-xuan          #+#    #+#             */
/*   Updated: 2024/12/09 11:15:10 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

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

int	is_sorted(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}
