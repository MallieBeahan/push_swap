/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_stack3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 17:54:29 by mbeahan           #+#    #+#             */
/*   Updated: 2019/08/06 20:00:25 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		dont_touch(t_block blocks, int size)
{
	int sum;
	int i;

	i = 0;
	sum = 0;
	while (i < size + 1)
	{
		sum += blocks.blocks[i];
		i++;
	}
	return (sum);
}

void	free_lst(t_list *lst)
{
	free(lst->stack_a);
	free(lst->stack_b);
	free(lst);
}

void	sort_three_elem(t_list *lst, t_block blocks)
{
	int max;
	int first;
	int second;

	first = 0;
	second = 0;
	lst->size_a == 2 && lst->stack_a[0] > lst->stack_a[1] ? sa(lst, 1) : 0;
	if (lst->size_a == 3)
	{
		first = lst->stack_a[0];
		second = lst->stack_a[1];
		if (first > second && first > lst->stack_a[2])
			max = 0;
		if (second > first && second > lst->stack_a[2])
			max = 1;
		max == 0 ? ra(lst, 1) : 0;
		max == 1 ? rra(lst, 1) : 0;
		lst->stack_a[0] > lst->stack_a[1] ? sa(lst, 1) : 0;
	}
	lst->sort_in_a = lst->size_a;
}
