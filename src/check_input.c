/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:40:12 by hni-xuan          #+#    #+#             */
/*   Updated: 2024/12/06 18:22:12 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

int	check_input(char **filtered_input, int **arr)
{
	int		num_count;
	int		i;
	long	num;

	num_count = counts_word(filtered_input);
	*arr = malloc(num_count * sizeof(int));
	if (!arr)
		return (0);
	i = -1;
	while (filtered_input[++i])
	{
		num = ft_atol(filtered_input[i]);
		if (num > INT_MAX || num < INT_MIN || non_int(filtered_input[i]))
		{	
			free(*arr);
			ft_free_arr(filtered_input, num_count);
			exit_error();
		}
		(*arr)[i] = (int) num;
	}
	ft_free_arr(filtered_input, num_count);
	check_duplicate(*arr, num_count);
	return (num_count);
}

int	counts_word(char **input)
{
	int	count;

	count = 0;
	while (input[count])
		count++;
	return (count);
}

long	ft_atol(char *str)
{
	long	sum;
	int		neg;

	sum = 0;
	neg = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' && (*(str + 1) >= '0' && *(str + 1) <= '9'))
		str++;
	if (*str == '-' && (*(str + 1) >= '0' && *(str + 1) <= '9'))
	{
		neg = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		sum = sum * 10 + (*str - '0');
		str++;
	}
	return (sum * neg);
}

void	check_duplicate(int *arr, int input_len)
{
	int	i;
	int	j;

	i = -1;
	while (++i < input_len)
	{
		j = i;
		while(++j < input_len)
		{
			if (arr[i] == arr[j])
				exit_error();
		}
	}
}

int	non_int(char *input)
{
	if((*input == '+' || *input == '-') && *(input + 1))
		input++;
	while(*input)
	{
		if (*input >= '0' && *input <= '9')
			input++;
		else
			return (1);	
	}
	return (0);
}
