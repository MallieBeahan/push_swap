/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 21:31:12 by mbeahan           #+#    #+#             */
/*   Updated: 2019/08/06 20:00:33 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	sort_stack_a(t_list *lst, t_block blocks, int size)
{
	if (size > 1 && lst->stack_a[0] > lst->stack_a[1])
		sa(lst, 1);
	if (size > 2 && lst->stack_a[1] > lst->stack_a[2])
	{
		ra(lst, 1);
		sa(lst, 1);
		rra(lst, 1);
	}
	if (size > 1 && lst->stack_a[0] > lst->stack_a[1])
		sa(lst, 1);
	lst->sort_in_a += size;
}

static void	clear_stack_more(t_list *lst, t_block blocks)
{
	int pivot;
	int count;
	int i;

	i = 0;
	pivot = find_pivot((const int *)lst->stack_a, lst->size_a - lst->sort_in_a);
	count = find_count((const int *)lst->stack_a,
	lst->size_a - lst->sort_in_a, pivot);
	i = cycle_drop(lst, count, pivot);
	restore_stack(lst, i);
	if (lst->size_a - lst->sort_in_a <= 3)
		sort_stack_a(lst, blocks, lst->size_a - lst->sort_in_a);
	else
	{
		blocks.blocks[lst->i] = find_size(lst, blocks);
		clear_stack_more(lst, blocks);
	}
}

static void	clear_stack_b(t_list *lst, t_block blocks)
{
	int flag;

	flag = 1;
	if (lst->size_b != dont_touch(blocks, lst->i))
	{
		if (lst->i == 0 && blocks.blocks[0] == 0)
			blocks.blocks[lst->i] = lst->size_b;
		else
		{
			blocks.blocks[lst->i] != 0 ? lst->i++ : 0;
			blocks.blocks[lst->i] = lst->size_b - dont_touch(blocks, lst->i);
		}
	}
	while (blocks.blocks[lst->i]--)
		pa(lst, 1);
	blocks.blocks[lst->i] = 0;
	lst->i != 0 ? lst->i-- : 0;
	if (lst->size_a - lst->sort_in_a <= 3)
	{
		sort_stack_a(lst, blocks, lst->size_a - lst->sort_in_a);
		flag = 0;
	}
	flag ? clear_stack_more(lst, blocks) : 0;
}

static void	clear_stack_a(t_list *lst, t_block blocks)
{
	int pivot;
	int count;

	pivot = 0;
	count = 0;
	pivot = find_pivot((const int *)lst->stack_a, lst->size_a);
	count = find_count(lst->stack_a, lst->size_a, pivot);
	while (count)
	{
		if (lst->stack_a[0] <= pivot)
		{
			pb(lst, 1);
			count--;
		}
		else
			ra(lst, 1);
	}
	if (lst->i == 0 && blocks.blocks[0] == 0)
		blocks.blocks[lst->i] = lst->size_b;
	else
	{
		if (blocks.blocks[lst->i] != 0)
			lst->i++;
		blocks.blocks[lst->i] = lst->size_b - dont_touch(blocks, lst->i);
	}
}

void		sort(t_list *lst)
{
	t_block	blocks;
	int		check;

	check = lst->size_a;
	ft_bzero(&blocks, sizeof(blocks));
	blocks.blocks = NULL;
	if (lst->size_a <= 3)
		sort_three_elem(lst, blocks);
	else
	{
		while (lst->size_a > 3)
		{
			if (!blocks.blocks)
				blocks.blocks = (int *)ft_memalloc(sizeof(int) * BLOCK_SIZE);
			clear_stack_a(lst, blocks);
		}
		sort_three_elem(lst, blocks);
		while (check > lst->sort_in_a)
			clear_stack_b(lst, blocks);
	}
	free_all(blocks, lst);
}
