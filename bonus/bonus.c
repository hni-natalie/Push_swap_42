/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:18:10 by hni-xuan          #+#    #+#             */
/*   Updated: 2024/12/09 11:19:16 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		input_len;
	char	**filtered_input;
	int		*arr;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	filtered_input = to_str_arr(argv + 1);
	input_len = check_input(filtered_input, &arr);
	stack_a = stack_init(arr, input_len);
	sort_index(&stack_a, input_len);
	checker(&stack_a, &stack_b);
	free_node(&stack_a);
	free(arr);
}

void	checker(t_stack **a, t_stack **b)
{
	char	*step;

	step = malloc(sizeof(char));
	if (!step)
		return ;
	while (step)
	{
		free(step);
		step = get_next_line(0);
		if (step)
			check_step(a, b, step);
	}
	if (is_sorted(a) && !(*b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	check_step(t_stack **a, t_stack **b, char *s)
{
	if (ft_strncmp(s, "sa\n", 3) == 0)
		sa(a);
	else if (ft_strncmp(s, "sb\n", 3) == 0)
		sb(b);
	else if (ft_strncmp(s, "ss\n", 3) == 0)
		ss(a, b);
	else if (ft_strncmp(s, "ra\n", 3) == 0)
		ra(a);
	else if (ft_strncmp(s, "rb\n", 3) == 0)
		rb(b);
	else if (ft_strncmp(s, "rr\n", 3) == 0)
		rr(a, b);
	else if (ft_strncmp(s, "rra\n", 4) == 0)
		rra(a);
	else if (ft_strncmp(s, "rrb\n", 4) == 0)
		rrb(b);
	else if (ft_strncmp(s, "rrr\n", 4) == 0)
		rrr(a, b);
	else if (ft_strncmp(s, "pa\n", 3) == 0)
		pa(b, a);
	else if (ft_strncmp(s, "pb\n", 3) == 0)
		pb(a, b);
	else
		exit_error();
}
