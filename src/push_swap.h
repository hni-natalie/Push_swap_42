/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:10:54 by hni-xuan          #+#    #+#             */
/*   Updated: 2024/12/03 19:46:59 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int				index;
	int				value;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

char	**to_str_arr(char **num);

int		counts_word(char **input);
long	ft_atol(char *char_num);
void	check_duplicate(int *arr, int input_len);
int		non_int(char *input);
int		check_input(char **filtered_input, int **arr);

void	exit_error();
void	ft_free_arr(char **filtered_input, int len);


#endif