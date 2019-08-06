/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_stack2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:49:32 by mbeahan           #+#    #+#             */
/*   Updated: 2019/08/06 20:00:23 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rrr(t_list *lst)
{
	if (lst)
	{
		rra(lst, 0);
		rrb(lst, 0);
		write(1, "rrr\n", 4);
		if (lst->visualize)
			visualize(lst);
	}
}

int		*copyarr(const int *arr, int k)
{
	int i;
	int *copy;

	i = 0;
	copy = (int *)malloc(sizeof(int) * k + 1);
	while (i < k)
	{
		copy[i] = arr[i];
		i++;
	}
	return (copy);
}

int		find_pivot(const int *arr, int size)
{
	int *new_arr;
	int pivot;

	pivot = 0;
	new_arr = copyarr(arr, size);
	sort_arr(new_arr, size);
	if (size % 2 == 0)
		pivot = ((new_arr[size / 2] + new_arr[(size / 2) - 1]) / 2);
	else
		pivot = new_arr[size / 2];
	free(new_arr);
	return (pivot);
}

int		find_size(t_list *lst, t_block blocks)
{
	int size;

	size = 0;
	if (lst->i == 0 && blocks.blocks[0] == 0)
		size = lst->size_b;
	else
	{
		if (blocks.blocks[lst->i] != 0)
			lst->i++;
		size = lst->size_b - dont_touch(blocks, lst->i);
	}
	return (size);
}

int		cycle_drop(t_list *lst, int count, int pivot)
{
	int i;

	i = 0;
	while (count)
	{
		if (lst->stack_a[0] <= pivot)
		{
			pb(lst, 1);
			count--;
		}
		else
		{
			ra(lst, 1);
			i++;
		}
	}
	return (i);
}
